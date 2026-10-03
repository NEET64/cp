# Contest Layout 🏆

**By Neet, for Neet, of Neet** — true democracy of competitive programming!

I wanted my code on top and input.txt / output.txt side by side below it, every time, without dragging tabs around. Plus one key to run, and no binaries lying around. Nothing did exactly that, so I made one. C++, Java and Python work out of the box, any other language is one line in settings.

## What it does

- **Layout:** code on top, `input.txt` and `output.txt` side by side below. Both are locked, so any other file you open goes to the code side, not on top of my input. Layout icon in the editor title bar, or **Neet: Set Contest Layout**. Missing files get created.
- **Run:** `Shift+Enter` or ▶, from the code file, input.txt or output.txt. It saves, compiles and runs in the background. The terminal stays closed, `Ctrl+J` shows the log. ⏹ stops a run, and a new run stops the old one.
- **Input** comes from input.txt if it exists, else you type in the terminal. input.txt is live: add a line, save, and the program gets it, so interactive problems work too.
- **Output** goes to output.txt if it exists, else the terminal. Errors and debug output (stderr) always go to the terminal, so output.txt has only the answer.
- **Result:** compile error, runtime error with exit code, TLE, or CPU time, real time and memory.
- **No binaries:** everything is built in a temp folder.
- **Faster C++:** `bits/stdc++.h` is precompiled in the background, so a compile takes about 0.7s instead of 2s.
- **New file:** the `+` icon or **Neet: New File** suggests the next letter (A, B, C…) and copies your template. Java class names get renamed to match.

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

- `{file}` is the source file path, `{name}` the file name without extension.
- Commands run in bash, so `"run": "timeout 2 ./{name}"` (time limit), `"run": "ulimit -s unlimited; ./{name}"` (big stack) or `-I"$HOME/dir"` just work.
- Your entries merge over the defaults: `"cpp": { "run": "timeout 2 ./{name}" }` keeps the default compile command.
- New language? One line, e.g. `"rs": { "compile": "rustc -O {file}", "run": "./{name}" }`.
- Different flags for one contest: put them in that folder's `.vscode/settings.json`.

## Good to know

- Live input never sends EOF, so read the test count instead of `while (cin >> x)` or `sys.stdin.read()`.
- CPU time is what judges limit. Real time also counts the time spent waiting for input.
- The program runs in the temp folder, so read stdin, not files by name.
- Needs bash (Linux, macOS; on Windows use WSL or Git Bash).
- The precompiled header lives in `~/.cache/contest-layout` (~170 MB) and rebuilds itself after a g++ update.
