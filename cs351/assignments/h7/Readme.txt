CS351 Assignment 7	10+ points

Convert each function, one by one, from the C code (crpn.c) to assembly (that
uses the C standard library.)  As you convert each function comment it out of
the C code (but leave the prototype at the top,) and replace it with an
assembly version in the rpn.s file.

An enum is just an "int" type.  In C T_NUMBER is actually 0.  You should
replace the enums with %defines in assembly.  The bool and token_t types are
really just int's.

Use 'make' to build the program from both the .c and .s files.  If you have
completely converted the program, use 'make asmrpn' to build the program
just from the rpn.s file.

Each function (and the global variables) is assigned a certain amount of
points.  The assignment is nominally worth 10 points, but you may earn up
to 20 points on this assignment.

You can use 'check' or 'handin --hwcheck' to check that your program still
works after each modification.
