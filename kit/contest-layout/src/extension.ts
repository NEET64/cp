import * as vscode from "vscode";
import * as path from "path";
import * as fs from "fs";
import * as os from "os";
import { spawn } from "child_process";
import { setTimeout as sleep } from "timers/promises";
import {
  Languages,
  buildScript,
  expandHome,
  fillCommand,
  nextFileName,
  pchJob,
  quote,
  renameJavaClass,
  withPch,
} from "./core";

const TERMINAL_NAME = "Contest Runner";
const PCH_CACHE = path.join(os.homedir(), ".cache", "contest-layout");

let terminal: vscode.Terminal | undefined;
let running: { doneFile: string; timer: NodeJS.Timeout } | undefined;
const lastRun = new Map<string, string>();
let lastNewExt: string | undefined;

function settings() {
  const config = vscode.workspace.getConfiguration("contestLayout");
  return {
    // VS Code deep-merges object settings, so setting only "run" of cpp keeps its default "compile".
    languages: config.get<Languages>("languages", {}),
    inputName: config.get<string>("inputFile", "input.txt"),
    outputName: config.get<string>("outputFile", "output.txt"),
  };
}

function extOf(file: string) {
  return path.extname(file).slice(1);
}

function isCodeFile(file: string) {
  return !!settings().languages[extOf(file)]?.run;
}

function isIoFile(file: string) {
  const { inputName, outputName } = settings();
  const name = path.basename(file);
  return name === inputName || name === outputName;
}

function activeFile() {
  const document = vscode.window.activeTextEditor?.document;
  return document && !document.isUntitled ? document.fileName : undefined;
}

// The folder of the open code/input/output file, else the workspace root.
function contestFolder() {
  const file = activeFile();
  if (file && (isCodeFile(file) || isIoFile(file))) return path.dirname(file);
  return vscode.workspace.workspaceFolders?.[0]?.uri.fsPath;
}

function firstCodeFile(folder: string) {
  const name = fs
    .readdirSync(folder)
    .sort()
    .find((file) => isCodeFile(file) && fs.statSync(path.join(folder, file)).isFile());
  return name && path.join(folder, name);
}

// ---------------------------
// Set Contest Layout: code on top, input and output side by side below it
// ---------------------------
async function openContestFiles() {
  try {
    const folder = contestFolder();
    if (!folder) {
      vscode.window.showErrorMessage("Open a folder first!");
      return;
    }

    const { inputName, outputName } = settings();
    const ioFiles = [path.join(folder, inputName), path.join(folder, outputName)];
    const active = activeFile();
    const codeFile = active && isCodeFile(active) ? active : visibleCodeFile(folder) ?? firstCodeFile(folder);
    if (!codeFile) {
      vscode.window.showErrorMessage(`No code file to open in ${folder}`);
      return;
    }

    // Close input/output tabs from before, so they don't end up twice (saved first, so no prompt).
    for (const file of ioFiles) if (!fs.existsSync(file)) fs.writeFileSync(file, "");
    for (const doc of vscode.workspace.textDocuments) {
      if (doc.isDirty && ioFiles.includes(doc.fileName)) await doc.save();
    }
    const ioTabs = vscode.window.tabGroups.all
      .flatMap((group) => group.tabs)
      .filter((tab) => tab.input instanceof vscode.TabInputText && ioFiles.includes(tab.input.uri.fsPath));
    await vscode.window.tabGroups.close(ioTabs);

    // Always new groups, made next to the code's group. ("Move to next group" reused existing
    // groups, so with two side-by-side groups output.txt landed in the other code group.)
    // Both are locked, so files opened later go to the code's group, not here.
    const codeColumn = vscode.window.visibleTextEditors.find((editor) => editor.document.fileName === codeFile)?.viewColumn;
    await vscode.window.showTextDocument(vscode.Uri.file(codeFile), { viewColumn: codeColumn, preview: false });
    await vscode.commands.executeCommand("workbench.action.newGroupBelow");
    await vscode.window.showTextDocument(vscode.Uri.file(ioFiles[0]), { preview: false });
    await vscode.commands.executeCommand("workbench.action.lockEditorGroup");
    await vscode.commands.executeCommand("workbench.action.newGroupRight");
    await vscode.window.showTextDocument(vscode.Uri.file(ioFiles[1]), { preview: false });
    await vscode.commands.executeCommand("workbench.action.lockEditorGroup");
    await vscode.commands.executeCommand("workbench.action.focusAboveGroup");
  } catch (error) {
    vscode.window.showErrorMessage(`Contest layout failed: ${(error as Error).message}`);
  }
}

// ---------------------------
// Run
// ---------------------------
function runnerTerminal() {
  if (!terminal || terminal.exitStatus) {
    terminal =
      vscode.window.terminals.find((t) => t.name === TERMINAL_NAME && !t.exitStatus) ??
      vscode.window.createTerminal(TERMINAL_NAME);
  }
  return terminal;
}

function visibleCodeFile(folder: string) {
  return vscode.window.visibleTextEditors
    .map((editor) => editor.document.fileName)
    .find((file) => path.dirname(file) === folder && isCodeFile(file));
}

function setRunning(value: typeof running) {
  running = value;
  vscode.commands.executeCommand("setContext", "contestLayout.running", !!value);
}

function finishRun() {
  if (!running) return;
  clearInterval(running.timer);
  fs.rmSync(running.doneFile, { force: true });
  setRunning(undefined);
}

// The run script creates doneFile when it exits; that flips Stop back to Run.
function watchRun(doneFile: string) {
  const timer = setInterval(() => {
    if (fs.existsSync(doneFile)) finishRun();
  }, 100);
  setRunning({ doneFile, timer });
}

async function stopRun() {
  if (!running) return;
  terminal?.sendText("\x03", false);
  for (let waited = 0; running && waited < 2000; waited += 100) await sleep(100);
  finishRun();
}

// The editor title button passes its tab's file; Shift+Enter passes nothing.
async function runFile(uri?: vscode.Uri) {
  const document = uri
    ? await vscode.workspace.openTextDocument(uri)
    : vscode.window.activeTextEditor?.document;
  if (!document) {
    vscode.window.showErrorMessage("No file open to run!");
    return;
  }
  if (document.isUntitled) {
    vscode.window.showErrorMessage("Save the file first.");
    return;
  }

  const { languages, inputName, outputName } = settings();
  let sourceFile = document.fileName;
  const folder = path.dirname(sourceFile);

  if (isIoFile(sourceFile)) {
    const codeFile = lastRun.get(folder) ?? visibleCodeFile(folder);
    if (!codeFile) {
      vscode.window.showErrorMessage("Open the code file once to run it.");
      return;
    }
    sourceFile = codeFile;
  }

  const ext = extOf(sourceFile);
  const language = languages[ext];
  if (!language?.run) {
    vscode.window.showErrorMessage(`No run command for .${ext} in contestLayout.languages.`);
    return;
  }

  const inputFile = path.join(folder, inputName);
  const outputFile = path.join(folder, outputName);
  for (const doc of vscode.workspace.textDocuments) {
    if (doc.isDirty && (doc.fileName === sourceFile || doc.fileName === inputFile)) {
      await doc.save();
    }
  }

  await stopRun();
  lastRun.set(folder, sourceFile);

  // A fresh temp dir per run, so runs in two VS Code windows never touch each other's files.
  const dir = fs.mkdtempSync(path.join(os.tmpdir(), "contest-layout-"));
  const doneFile = `${dir}.done`;
  const hasInput = fs.existsSync(inputFile);
  const script = path.join(dir, "run.sh");
  fs.writeFileSync(
    script,
    buildScript({
      dir,
      doneFile,
      sourceFile,
      compile: language.compile ? compileCommand(language.compile, sourceFile) : "",
      run: fillCommand(language.run, sourceFile),
      inputFile: hasInput ? inputFile : undefined,
      outputFile: fs.existsSync(outputFile) ? outputFile : undefined,
    })
  );

  const runner = runnerTerminal();
  // Runs in the background (Ctrl+J shows the log). Only without input.txt the
  // program reads from the terminal, so then it is opened and focused for typing.
  if (!hasInput) runner.show(false);
  runner.sendText(`bash ${quote(script)}`);
  watchRun(doneFile);
}

function compileCommand(raw: string, sourceFile: string) {
  const command = fillCommand(raw, sourceFile);
  const pch = pchJob(raw, PCH_CACHE);
  return pch ? withPch(command, pch.dir) : command;
}

// ---------------------------
// Precompiled bits/stdc++.h, checked and built in the background so a run never waits for it
// ---------------------------
const pchBuilding = new Set<string>();

function warmPrecompiledHeaders() {
  const jobs = Object.values(settings().languages).flatMap(
    (language) => pchJob(language.compile ?? "", PCH_CACHE) ?? []
  );

  const pchRoot = path.join(PCH_CACHE, "pch");
  for (const name of fs.existsSync(pchRoot) ? fs.readdirSync(pchRoot) : []) {
    const dir = path.join(pchRoot, name);
    if (!jobs.some((job) => job.dir === dir) && !pchBuilding.has(dir)) {
      fs.rmSync(dir, { recursive: true, force: true });
    }
  }

  for (const job of jobs) {
    if (pchBuilding.has(job.dir)) continue;
    const header = path.join(job.dir, "all.h");
    fs.mkdirSync(path.join(job.dir, "bits"), { recursive: true });
    // Written once only: rewriting it while another window's g++ reads it could give an empty PCH.
    if (!fs.existsSync(header)) fs.writeFileSync(header, "#include <bits/stdc++.h>\n");
    pchBuilding.add(job.dir);
    const done = () => pchBuilding.delete(job.dir);
    spawn("nice", ["-n", "10", "bash", "-c", job.build], { stdio: "ignore" }).on("close", done).on("error", done);
  }
}

// ---------------------------
// New file from template
// ---------------------------
async function newFile() {
  const folder = contestFolder();
  if (!folder) {
    vscode.window.showErrorMessage("Open a folder first!");
    return;
  }

  const { languages } = settings();
  const file = activeFile();
  const current = file && languages[extOf(file)] ? extOf(file) : lastNewExt;
  const exts = Object.keys(languages).sort(
    (a, b) => Number(b === current) - Number(a === current)
  );

  const settingsItem = { label: "$(gear) Edit templates in settings" };
  const pick = await vscode.window.showQuickPick(
    [
      ...exts.map((ext) => ({
        label: ext,
        description: languages[ext].template || "(no template)",
      })),
      settingsItem,
    ],
    { placeHolder: "Language for the new file" }
  );
  if (!pick) return;
  if (pick === settingsItem) {
    vscode.commands.executeCommand("workbench.action.openSettings", "contestLayout.languages");
    return;
  }

  const suggested = nextFileName(fs.readdirSync(folder), pick.label);
  const name = await vscode.window.showInputBox({
    prompt: `New file in ${folder}`,
    value: suggested,
    valueSelection: [0, suggested.length - pick.label.length - 1],
  });
  if (!name) return;

  const fileName = path.extname(name) ? name : `${name}.${pick.label}`;
  const target = path.join(folder, fileName);
  const ext = extOf(target);

  if (!fs.existsSync(target)) {
    let code = "";
    const template = languages[ext]?.template;
    if (template) {
      const templateFile = expandHome(template);
      if (!fs.existsSync(templateFile)) {
        vscode.window.showErrorMessage(`Template not found: ${templateFile}`);
        return;
      }
      code = fs.readFileSync(templateFile, "utf8");
    }
    if (ext === "java") code = renameJavaClass(code, path.basename(target, ".java"));
    fs.writeFileSync(target, code);
  }

  lastNewExt = ext;
  await vscode.window.showTextDocument(vscode.Uri.file(target), { preview: false });
}

// ---------------------------
// Context keys for the Shift+Enter keybinding and the editor title buttons
// ---------------------------
function updateContext() {
  const { languages, inputName, outputName } = settings();
  const runnable = Object.keys(languages)
    .filter((ext) => languages[ext].run)
    .map((ext) => `.${ext}`);
  vscode.commands.executeCommand("setContext", "contestLayout.runnableExts", runnable);
  vscode.commands.executeCommand("setContext", "contestLayout.ioFiles", [inputName, outputName]);
  updateLayoutReady();
}

function updateLayoutReady() {
  const file = activeFile();
  const { inputName, outputName } = settings();
  const visible = vscode.window.visibleTextEditors.map((editor) => editor.document.fileName);
  const ready =
    !!file &&
    visible.includes(path.join(path.dirname(file), inputName)) &&
    visible.includes(path.join(path.dirname(file), outputName));
  vscode.commands.executeCommand("setContext", "contestLayout.layoutReady", ready);
}

export function activate(context: vscode.ExtensionContext) {
  context.subscriptions.push(
    vscode.commands.registerCommand("contestLayout.openContestFiles", openContestFiles),
    vscode.commands.registerCommand("contestLayout.runFile", runFile),
    vscode.commands.registerCommand("contestLayout.stopRun", stopRun),
    vscode.commands.registerCommand("contestLayout.newFile", newFile),
    vscode.window.onDidChangeActiveTextEditor(updateLayoutReady),
    vscode.window.onDidChangeVisibleTextEditors(updateLayoutReady),
    vscode.window.onDidCloseTerminal((closed) => {
      if (closed === terminal) {
        terminal = undefined;
        finishRun();
      }
    }),
    vscode.workspace.onDidChangeConfiguration((event) => {
      if (event.affectsConfiguration("contestLayout")) {
        updateContext();
        warmPrecompiledHeaders();
      }
    }),
    { dispose: finishRun }
  );

  updateContext();
  warmPrecompiledHeaders();
}
