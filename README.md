# cp

I like things organized, and a few small things kept bugging me while doing CP. So I fixed them, one by one. This is where my solutions and those fixes live.

## gen

Every contest started the same way: make a folder, make A, B, C, paste the template into each, make input.txt and output.txt, open the folder in VS Code. Every. Single. Time.

```bash
gen contest 2134   # folder + A/B/C from the template + input/output, opens in VS Code
gen cpp D      # one file from the template, in the current folder
gen py E       # same for Python, when I don't want to think about overflow
gen java Main
```

## Contest Layout

input.txt and output.txt beat scrolling through one terminal. But every run left a binary next to my solution (OCD, can't stand it), and I wanted my files in exactly this layout (don't ask me why):

```
┌───────────────────────────────┐
│            A.cpp              │
├───────────────┬───────────────┤
│   input.txt   │  output.txt   │
└───────────────┴───────────────┘
```

Not left, not right, not in a panel. This one. Existing extensions didn't do that, so I made one:

- one click sets up the layout, and creates input.txt / output.txt if they're missing
- `Shift+Enter` saves, compiles and runs from any of the three files
- builds in a temp folder, so no binary is left behind
- input.txt is live: append a line, save, and the running program gets it

It also precompiles `bits/stdc++.h`, so compiles are faster. More in its [README](kit/contest-layout/README.md).

## CPH, for practice

Not mine, but a big part of practice. [Competitive Programming Helper](https://github.com/agrawal-d/cph) grabs a problem's test cases from the browser and opens a file from my template with the input and expected output already there. Run, check, and submit right from VS Code. For contests, gen + the layout above is enough.

## debug.h

I hate writing a loop to print an array, nested loops for a 2D array or a map, and above all:

```cpp
cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
```

I saw something like this in tourist's submissions and wanted my own:

```cpp
debug(i, sum, dp, grid);
```

```
i = 3, sum = 17
dp = [0, 1, 1, 2]
grid =
  [ 0,  1,  2]
  [ 1, 10,  3]
```

Nested anything works, and it prints in pretty colors.

## Snippets

The plan: whenever I catch myself writing the same code for the hundredth time, like building an adjacency list from a list of edges, it goes into `snippets/`. Then `gen snippets`, and in any file I type `adj`, pick it from the suggestions, and it's there. Right now there's only `sieve`, and it'll grow as I go.

---

Nothing fancy, and people out there have way crazier setups. This one just fits me.
