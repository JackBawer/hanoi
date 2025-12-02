# hanoi

A small C implementation of the Tower of Hanoi puzzle and helper utilities. This repository is written primarily in C (≈93.7%) with a small Makefile (≈6.3%) to build the project.

This README explains how to get the code, build it with `make`, and run the resulting executable (`./hanoi`). It also includes usage examples, troubleshooting tips, and contribution notes.

---

Table of contents
- About
- Prerequisites
- Get the code
- Build
- Run / Usage
- Example
- Common make targets
- Troubleshooting
- Contributing
- License

---

About
-----
The program demonstrates the Tower of Hanoi solution (or similar puzzle solver) in C. It compiles to a small command-line executable named `hanoi`. Use it to observe the sequence of moves or to integrate into scripts.

Prerequisites
-------------
- A POSIX-compatible environment (Linux, macOS, or WSL on Windows)
- A C compiler (gcc, clang) and standard build tools
- make

Get the code
------------
Clone the repository locally:

```
git clone https://github.com/JackBawer/hanoi.git
cd hanoi
```

Build
-----
Build the project with make (default target):

```
make
```

This should produce an executable called `hanoi` in the repository root (or in the configured build/output path).

If you want to build using multiple cores:

```
make -j$(nproc)
```

Run / Usage
-----------
The program is run from the command line. Typical forms:

- Show help (if supported by the program):
  ```
  ./hanoi --help
  ./hanoi -h
  ```

- Run with a number of disks (common usage):
  ```
  ./hanoi 3
  ```

Replace `3` with the number of disks you want to solve for. If the program accepts additional options, `--help` will list them.

Note: if you see a permission error, make the binary executable:
```
chmod +x ./hanoi
```

Example
-------
Run a 3-disk example:

```
./hanoi 3
```

Typical output for a Tower of Hanoi solver will be a list of moves similar to:

```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

(Actual output format depends on this repository's implementation. Use `--help` to view exact flags and output formatting.)

Common make targets
------------------
- `make` — build the project (default)
- `make clean` — remove build artifacts (object files, binaries)
- `make test` — run tests (if provided in the Makefile)
- `make install` — install the binary (if implemented)

If the repository's Makefile differs, inspect it with:
```
sed -n '1,200p' Makefile
```
or open it in your editor to see available targets.

Troubleshooting
---------------
- "make: command not found": install make (e.g., `sudo apt install build-essential` on Debian/Ubuntu).
- Compiler errors: ensure you have a C compiler installed (gcc/clang) and the correct development headers.
- Permission denied when running `./hanoi`: run `chmod +x ./hanoi`.
- Unexpected behavior or crashes: try running under a debugger:
  ```
  gdb --args ./hanoi 5
  ```
  or add debugging prints / compile with `-g -O0` if you modify the Makefile/compile flags.

Contributing
------------
Contributions are welcome:
- Open issues to report bugs or request features.
- Submit pull requests with clear descriptions and tests (if applicable).
- Keep changes small and focused; follow any coding style described in the repo.

License
-------
Check the repository for a LICENSE file to confirm licensing terms.

Contact
-------
If you have questions about running or building the project, open an issue in the repository, and the maintainers will help.

---

Enjoy exploring the Tower of Hanoi implementation! If you'd like, I can also:
- Add a short usage example programmatically (e.g., wrap runs in a script),
- Create a more detailed CONTRIBUTING.md,
- Or open a PR that adds a `--help` flag or example Makefile targets if they're missing.
