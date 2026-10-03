import * as crypto from "crypto";
import * as os from "os";
import * as path from "path";

export interface Language {
  compile?: string;
  run?: string;
  template?: string;
}

export type Languages = Record<string, Language>;

export interface PchJob {
  dir: string;
  build: string;
}

export interface ScriptOptions {
  dir: string;
  doneFile: string;
  sourceFile: string;
  compile: string;
  run: string;
  inputFile?: string;
  outputFile?: string;
}

export function quote(text: string): string {
  return `'${text.replace(/'/g, `'\\''`)}'`;
}

// A replacer function, so a "$" or "{name}" inside the path stays as it is.
export function fillCommand(command: string, sourceFile: string): string {
  const name = path.basename(sourceFile, path.extname(sourceFile));
  return command.replace(/\{(file|name)\}/g, (_, key) => quote(key === "file" ? sourceFile : name));
}

export function expandHome(file: string): string {
  return file.startsWith("~/") ? path.join(os.homedir(), file.slice(2)) : file;
}

// For a g++ compile command: the dir for a precompiled bits/stdc++.h made with exactly
// these flags, and a bash command that rebuilds it unless g++ accepts the current one
// (g++ silently ignores a PCH made by another g++ build, e.g. before an update).
// Compiling with -I<dir> uses it; while it doesn't exist, g++ uses the normal header.
export function pchJob(compile: string, cacheRoot: string): PchJob | undefined {
  const flags = compile.replace(/\s*-o\s+\{name\}/, "").replace(/\s*\{file\}/, "").trim();
  if (!/^(\S*[/-])?g\+\+\S*(\s|$)/.test(flags) || !compile.includes("{file}")) return undefined;
  const dir = path.join(cacheRoot, "pch", crypto.hash("sha1", flags).slice(0, 16));
  const header = quote(path.join(dir, "all.h"));
  const gch = quote(path.join(dir, "bits", "stdc++.h.gch"));
  const check = `[ -f ${gch} ] && ${flags} -I${quote(dir)} -Werror=invalid-pch -fsyntax-only -x c++ ${header} 2>/dev/null`;
  // Built under a name unique to this build, then renamed, so two windows never write one file.
  return { dir, build: `${check} || { ${flags} -x c++-header ${header} -o ${gch}.$$ && mv ${gch}.$$ ${gch}; }` };
}

export function withPch(compile: string, pchDir: string): string {
  return compile.replace(/^\S+/, (compiler) => `${compiler} -I${quote(pchDir)}`);
}

export function nextFileName(existing: string[], ext: string): string {
  let next = "A";
  for (const file of existing) {
    const base = path.basename(file, path.extname(file));
    if (/^[A-Y]$/.test(base) && base >= next) {
      next = String.fromCharCode(base.charCodeAt(0) + 1);
    }
  }
  return `${next}.${ext}`;
}

export function renameJavaClass(code: string, name: string): string {
  return code.replace(/public class [A-Za-z_][A-Za-z0-9_]*/, `public class ${name}`);
}

const LANGUAGE_NAMES: Record<string, string> = { cpp: "C++", java: "Java", py: "Python" };

// Builds the bash script for one run. The program is compiled and run inside a temp
// dir so the contest folder stays clean, and input.txt is "live": after the current
// content is sent, every byte appended (and saved) later is sent too. A save
// truncates the file first, so a size drop is ignored instead of re-sending everything.
export function buildScript(o: ScriptOptions): string {
  const fileName = path.basename(o.sourceFile);
  const ext = path.extname(fileName).slice(1);
  const language = LANGUAGE_NAMES[ext] ?? ext;
  const input = o.inputFile ? `< "$D/stdin"` : "";
  const output = o.outputFile ? `> ${quote(o.outputFile)}` : "";
  const outputNote = o.outputFile ? ` Output written to ${path.basename(o.outputFile)}` : "";
  const compileStep = o.compile ? `bash -c ${quote(o.compile)} || { echo "❌ Compilation failed!"; exit 1; }` : "";
  const liveInput = o.inputFile
    ? `IN=${quote(o.inputFile)}
feed() {
  sent=0
  while :; do
    size=$(wc -c < "$IN" 2>/dev/null) || size=0
    size=\${size// /}
    if [ "$size" -gt "$sent" ]; then
      tail -c +$((sent + 1)) "$IN" | head -c $((size - sent))
      sent=$size
    fi
    sleep 0.2
  done
}
[ -s "$IN" ] || echo "⚠ Waiting for input in ${path.basename(o.inputFile)}..."
mkfifo "$D/stdin"
feed > "$D/stdin" &`
    : "";

  return `D=${quote(o.dir)}
DONE=${quote(o.doneFile)}
finish() {
  kill $(jobs -p) 2>/dev/null
  rm -rf "$D"
  : > "$DONE"
}
trap finish EXIT
cd "$D" || exit 1
echo "Running ${language} file: ${fileName}"
${compileStep}
${liveInput}
WRAP=()
/usr/bin/time --version > /dev/null 2>&1 && WRAP=(/usr/bin/time -f %M -o "$D/mem")
exec 3>&2
TIMEFORMAT='%U %S %R'
{ time "\${WRAP[@]}" bash -c ${quote(o.run)} ${input} ${output} 2>&3 ; } 2> "$D/time"
status=$?
read -r user sys real < "$D/time"
usage=$(awk "BEGIN { printf \\"%.2fs CPU, %.2fs real\\", $user + $sys, $real }")
[ -f "$D/mem" ] && usage="$usage, $(tail -n 1 "$D/mem" | awk '{ printf "%.1f MB", $1 / 1024 }')"
if [ "$status" -eq 0 ]; then
  echo "✅ Execution completed in $usage.${outputNote}"
elif [ "$status" -eq 124 ]; then
  echo "❌ Time limit exceeded!"
else
  echo "❌ Runtime error! (exit code $status)"
fi
`;
}
