/*
  Programming concept: nested loops

  Program should:      print a 10x10 checkerboard pattern (nested loops and print ' ' if i+j is even, else print '*')
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, j;
  for (i = 0; i < 10; i++)
  {
      for (j = 0; j <= 10; j++)
      {
          if ((i + j) % 2 == 0)
          {
              printf(" ");
          }
          else
          {
             printf("*");
          }
      }
      printf("\n");
  }


  return 0;
}
