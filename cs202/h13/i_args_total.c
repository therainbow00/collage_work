/*
  Programming concept: command line arguments

  Program should:      assume the command line arguments are all integers, add them up and print the result
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, count = 0;
  for (i = 1; i < argc; i++)
  {
      count += atoi(argv[i]);
  }
  printf("%d\n", count);


  return 0;
}
