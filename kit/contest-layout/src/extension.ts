import * as vscode from "vscode";
import * as path from "path";
import * as fs from "fs";
import * as os from "os";

export function activate(context: vscode.ExtensionContext) {
  // ---------------------------
  // 1️⃣ Set Contest Layout
  // ---------------------------
  const contestLayoutCmd = vscode.commands.registerCommand(
    "contestLayout.openContestFiles",
    async () => {
      const folder = vscode.workspace.workspaceFolders?.[0];
      if (!folder) {
        vscode.window.showErrorMessage("Open a folder first!");
        return;
      }

      const aFile = vscode.Uri.file(path.join(folder.uri.fsPath, "A.java"));
      const inputFile = path.join(folder.uri.fsPath, "input.txt");
      const outputFile = path.join(folder.uri.fsPath, "output.txt");

      if (!fs.existsSync(inputFile)) fs.writeFileSync(inputFile, "");
      if (!fs.existsSync(outputFile)) fs.writeFileSync(outputFile, "");

      const inputUri = vscode.Uri.file(inputFile);
      const outputUri = vscode.Uri.file(outputFile);

      if (!vscode.window.activeTextEditor) {
        await vscode.window.showTextDocument(aFile, {
          viewColumn: vscode.ViewColumn.One,
          preview: false,
        });
      }

      await vscode.window.showTextDocument(inputUri, {
        preview: false,
        preserveFocus: true,
      });
      await vscode.commands.executeCommand(
        "workbench.action.moveEditorToBelowGroup"
      );

      await vscode.window.showTextDocument(outputUri, {
        preview: false,
        preserveFocus: true,
      });
      await vscode.commands.executeCommand(
        "workbench.action.moveEditorToNextGroup"
      );
    }
  );

  // ---------------------------
  // 2️⃣ Run Java, Cpp, or Python
  // ---------------------------
  const runFileCmd = vscode.commands.registerCommand(
    "contestLayout.runFile",
    async () => {
      const editor = vscode.window.activeTextEditor;
      if (!editor) {
        vscode.window.showErrorMessage("No file open to run!");
        return;
      }

      const filePath = editor.document.fileName;
      const folder = path.dirname(filePath);
      const baseName = path.basename(filePath, path.extname(filePath));
      const ext = path.extname(filePath).toLowerCase();

      const inputFile = path.join(folder, "input.txt");
      const outputFile = path.join(folder, "output.txt");
      const outputExists = fs.existsSync(outputFile);

      const terminal =
        vscode.window.activeTerminal ||
        vscode.window.createTerminal("Contest Runner");
      terminal.show();

      const tempScriptPath = path.join(os.tmpdir(), `run_${baseName}.sh`);
      const isWindows = process.platform === "win32";

      let compileCmd = "";
      let runCmd = "";
      let cleanupCmd = "";

      if (ext === ".java") {
        compileCmd = `javac "${filePath}"`;
        runCmd = `java "${baseName}"`;
        cleanupCmd = `rm -f "${baseName}.class"`;
      } else if (ext === ".cpp") {
        compileCmd = `g++ -std=c++17 -O2 -Wall "${filePath}" -o "${baseName}"`;
        runCmd = `./${baseName}`;
        cleanupCmd = `rm -f "${baseName}"`;
      } else if (ext === ".py") {
        // Use python executable depending on OS
        runCmd = isWindows
          ? `"${process.env["PYTHON"] || "python"}" "${filePath}"`
          : `python3 "${filePath}"`;
        compileCmd = ""; // Python doesn't need compilation
        cleanupCmd = "";
      } else {
        vscode.window.showErrorMessage(
          "Only Java, C++, and Python files supported."
        );
        return;
      }

      const scriptContent = `
echo "Running ${
        ext === ".py" ? "Python" : ext === ".cpp" ? "C++" : "Java"
      } file: ${baseName}${ext}"

${compileCmd ? `${compileCmd}` : ""}

if [ $? -ne 0 ]; then
  echo "❌ Compilation failed!"
  rm -- "$0"
  exit 1
fi

if [ -f "${inputFile}" ]; then
  if [ ! -s "${inputFile}" ]; then
    echo "⚠ Waiting for input in input.txt..."
  fi
  while [ ! -s "${inputFile}" ]; do sleep 1; done
  ${runCmd} < "${inputFile}" ${outputExists ? `> "${outputFile}"` : ""}
else
  ${runCmd} ${outputExists ? `> "${outputFile}"` : ""}
fi

if [ $? -ne 0 ]; then
  echo "❌ Runtime error!"
else
  ${
    outputExists
      ? `echo "✅ Execution completed. Output written to output.txt"`
      : `echo "✅ Execution completed."`
  }
fi

${cleanupCmd}
rm -- "$0"
`;

      fs.writeFileSync(tempScriptPath, scriptContent, { encoding: "utf-8" });
      fs.chmodSync(tempScriptPath, 0o755);

      // Run using bash or cmd for Windows
      if (isWindows) {
        terminal.sendText(`bash "${tempScriptPath}"`);
      } else {
        terminal.sendText(`bash "${tempScriptPath}"`);
      }
    }
  );

  context.subscriptions.push(contestLayoutCmd, runFileCmd);
}

export function deactivate() {}

// npx tsc
// code --extensionDevelopmentPath="D:\Coding\Projects\contest-layout" "D:\Coding\CodeForces\testing"
// vsce package

function getFileName(filePath: string) {
  return (
    <div className="file-name h-10" id="asdfasdfasdfasdf">     {path.basename(filePath)}
    </div>

    <div className="file-name" id="123123123123">
      {path.basename(filePath)}
    </div>

  );
}
