# Contest Layout 🏆

**By Neet, for Neet, of Neet** — true democracy of competitive programming!

Contest layout and one-key runner for competitive programming in VS Code. C++, Java and Python work out of the box, and any other language is one line in settings.

## What it does

- **Contest layout:** code on top, `input.txt` and `output.txt` side by side below it. Both are locked, so other files you open go to the code side. Use the layout icon in the editor title bar or **Neet: Set Contest Layout**. Missing files are created.
- **Run with `Shift+Enter`** or the ▶ icon, from the code file, input.txt or output.txt. It saves, compiles and runs in the background: the terminal stays closed, `Ctrl+J` shows the log. ⏹ stops a run, and a new run stops the old one.
- **Input** comes from input.txt if it exists, else you type it in the terminal. input.txt is live: append lines and save to send more, so interactive problems work too.
- **Output** goes to output.txt if it exists, else to the terminal. Errors and debug output (stderr) always go to the terminal.
- **Result line:** compile error, runtime error with exit code, time limit exceeded, or CPU time, real time and memory.
- **Clean folder:** everything is built in a temp folder, so no binaries or `.class` files are left behind.
- **Fast C++ compile:** `bits/stdc++.h` is precompiled in the background, so a compile takes about 0.8s instead of 2s.
- **New file from template** with the `+` icon or **Neet: New File**: it suggests the next letter (A, B, C…) and copies your template. Java class names are renamed to match the file.

## Settings

```jsonc
"contestLayout.languages": {
  "cpp":  { "compile": "g++ -std=c++23 -O2 -Wall -DLOCAL {file} -o {name}", "run": "./{name}", "template": "~/templates/template.cpp" },
  "java": { "compile": "javac -d . {file}", "run": "java {name}" },
  "py":   { "run": "python3 {file}" }
},
"contestLayout.inputFile": "input.txt",
"contestLayout.outputFile": "output.txt"
```

- `{file}` is the source file path and `{name}` the file name without extension.
- Commands run in bash, so `"run": "timeout 2 ./{name}"` (time limit), `"run": "ulimit -s unlimited; ./{name}"` (big stack) or `-I"$HOME/dir"` just work.
- Your entries are merged over the defaults: `"cpp": { "run": "timeout 2 ./{name}" }` keeps the default compile command.
- Add a language with one line, e.g. `"rs": { "compile": "rustc -O {file}", "run": "./{name}" }`.
- Different flags for one contest: put them in that folder's `.vscode/settings.json`.

## Good to know

- Live input never sends EOF, so read the test count instead of `while (cin >> x)` or `sys.stdin.read()`.
- CPU time is what judges limit. Real time also counts the time spent waiting for input.
- The program runs in the temp folder, so read stdin, not files by name.
- Needs bash (Linux, macOS; on Windows use WSL or Git Bash).
- The precompiled header lives in `~/.cache/contest-layout` (~170 MB) and is rebuilt automatically after a g++ update.
