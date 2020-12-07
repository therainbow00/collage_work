/*
  Programming concept: nested loops

  Program should:      print out the multiplication table for numbers 0-9, it should be 10x10
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  for (int x = 0; x < 10; x++)
  {
      if (x < 1)
      {
          printf("       %d", x);
      }
      else
      {
          printf("   %d", x);
      }
  }

  printf("\n");

  for (int i = 0; i < 10; i++)
  {
      printf("  %d|", i);
      for (int j = 0; j < 10; j++)
      {
          if ((j * i) >= 10)
          {
              printf("  %d", i * j);
          }
          else
          {
              printf("   %d", i * j);
          }
      }
      printf("\n");
  }

  return 0;
}
