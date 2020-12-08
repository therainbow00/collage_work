/*
  Programming concept: dynamic memory array

  Program should:      ask the user for how many integers they will enter, use malloc to allocate memory for an array for that many items, then use a for loop to read the entries from the user into the malloc'ed array, then print out the numbers in reverse order.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int num, *m, i, n;
  printf("How many integers? ");
  scanf("%d", &num);

  m = (int *) malloc(num * sizeof(int));

  for (i = 0; i < num; i++)
  {
      printf("Integer please: ");
      scanf("%d", &m[i]);
  }

  printf("In reverse, that is...\n");

  for (n = num - 1; n >= 0; n--)
  {
      printf("%d\n", m[n]);
  }
  return 0;
}
