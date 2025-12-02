# Towers of Hanoi - C Project

This repository contains implementations of the Tower of Hanoi puzzle in C, both **recursive** and **iterative** versions. The project benchmarks execution time and move counts for different numbers of disks.

## Files

```
main.c          # Main file to run tests
recursive.c     # Recursive Hanoi implementation
iterative.c     # Iterative Hanoi implementation
hanoi.h         # Optional header file
Makefile        # Build automation
```

## Build

Use the provided Makefile:

```bash
make
```

This will produce the executable `hanoi`.

Alternatively, compile directly with gcc:

```bash
gcc main.c recursive.c iterative.c -Wall -O2 -o hanoi
```

## Run

After building, run:

```bash
./hanoi
```

The program will print a table of disk counts, execution times, and move counts for both recursive and iterative methods.

## Clean

To remove object files and the executable:

```bash
make clean
```

## Notes

* Object files (`*.o`) and the executable are ignored in Git via `.gitignore`.
* Designed for educational purposes; works on Linux/macOS or any POSIX environment.

