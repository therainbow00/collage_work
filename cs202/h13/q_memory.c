/*
  Programming concept: different parts of memory

  Program should:      create arrays that are local variables, global variables, and in dynamic memory.  print the memory addresses (%p) for the first location in each of the arrays and the second location in each of the arrays.  create two dummy functions, and print the memory addresses of the two dummy functions, main, and printf.  for all of those, include in the printout what you are printing.

 */

#include <stdio.h>
#include <stdlib.h>

void array()
{
    int arr_l[] = {1, 2, 3};
}

void dummy1()
{

}

void dummy2()
{
}

int main(int argc, char *argv[]) {
  int arr_g[] = {1, 2, 3}, *dynamic_arr_p;
  dynamic_arr_p = (int *) malloc(3 * sizeof(int));

  for (int i = 0; i < 3; i++)
  {
      dynamic_arr_p[i] = i;
  }
  //printf("%d\n", (sizeof(dynamic_arr_p) / sizeof(int)));
  printf("Global array G\n"
         "  &G[0]:   %p\n"
         "  &G[1]:   %p\n"
         "Local array L\n"
         "  &L[0]:   %p\n"
         "  &L[1]:   %p\n"
         "Dynamic array P\n"
         "  &P[0]:   %p\n"
         "  &P[1]:   %p\n"
         "Functions dummy1, dummy2, main, printf\n"
         "  &dummy1: %p\n"
         "  &dummy2: %p\n"
         "  &main:   %p\n"
         "  &printf: %p\n", arr_g, arr_g, array, array, dynamic_arr_p, dynamic_arr_p, dummy1, dummy2, main, printf);


  return 0;
}
