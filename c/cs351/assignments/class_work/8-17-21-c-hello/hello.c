/**
 * Include the stdio header file in our program, which defines
 * functions and data structures needed by the C standard library
 * for input and output functions, such as printf() and scanf(), etc.
 */
#include <stdio.h>

/**
 * Defines the entry function (main) for this C program.  All C
 * programs start with the "main" function.  And main always "returns"
 * as its value a integer (the "int" type).
 *
 * To compile:
 *   gcc -o hello hello.c
 */
int main(void)
{
  printf("Hello, world!\n");

  /**
   * Return gives a function its value. In the case of main, a 0
   * return value means the program was successful.  A non-zero value
   * means it failed in some way.
   */
//  return 0;
}
