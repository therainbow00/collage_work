CS351 Assignment 5	10 Points

Create an X86_64 assembly program (h5.s) using the "p.c" C program as the basis
for your assembly code.  Consider converting the program line by line to
assembly.  Considering doing so in these steps:

1) Replace variable names with register names where applicable, not every
   variable can be a register (i.e. num below should be in memory)

2) Define the string constants in the data section.

3) Convert any for loops to while loops

4) Convert each statement using the templates found in the asm.pdf

The lib.s and lib.h files are provided for you to use for the library functions
puts, putchar, and exit.  These functions do not preserve the system call
registers.


Hints:
- The input that is read from the file is in the form of byte values, i.e. very
  similar to the getchar() function that you will find in the lib.s file.

- The value of argc is at [rsp] (i.e. the first 64 bit value on the stack)

- The value of argv[1] is at [rsp+16]

- Do not attempt to access argc/argv except in your _start function, as calling
  a function will push the return address onto the stack, modifying the value
  of rsp, or keep in mind that the rsp value will be increased by 16.
