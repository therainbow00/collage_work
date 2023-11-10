CS456 Assignment #3	10 points

Convert the cpipe.c file into an assembly program in pipe.s.  Convert it in a
manner similar to the way I converted the rpn program from 01-24-Asm1, i.e.
one function at a time.  Use the C calling conventions for functions and each
function that uses local variables should store them in the functions stack
frame.

You may comment out the function in the C program as you add it to the .s file
and test it.  Make will compile and link both the C and assembly together.  Once
you have completed the assembly program you can compile it stand-alone with
'make asmpipe'
