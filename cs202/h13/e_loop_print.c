/*
  Programming concept: for loop

  Program should:      ask user for start and stop integers, print integers from start to stop
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int start, stop;
  printf("Start (int): ");
  scanf("%d", &start);

  printf("Stop (int): ");
  scanf("%d", &stop);

  for (start; start <= stop; start++)
  {
      printf("%d\n", start);
  }

  return 0;
}
