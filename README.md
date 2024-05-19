# Malloc
## What is malloc?
Malloc is a C function that allocates dynamic memory, if you ever programmed in C probably already encountered it.

## Context
As a school project I had recreate my own malloc function and theoretically be able to use it in any of my program. We also had along the way to recreate the functions free, calloc, realloc and reallocarray. You can find those functions in the source file, feel free to have a look at them.

## Compilation
The program compiles using a Makefile and you can use the rules: `make`, `make clean`, `make fclean` and `make re`. Make sure you have C and Make installed on your linux machine to launch the program.

To compile run this command:
```bash
make
```

The makefile compiles a shared library (.so) so you can use it in any of you C program right away.
