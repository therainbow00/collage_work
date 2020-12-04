/*
  Programming concept: array, read into with a loop

  Program should:      declare an array of 5 integers, for loop to ask user for 5 integers, read them into the array, then print the array in reverse order
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[6], i, j;
  size_t length = (sizeof(arr) / sizeof(int)) - 1;

  for (i = 0; i < length; i++)
  {
      printf("int please: ");
      scanf("%d", &arr[i]);
  }
  printf("In reverse order that is...\n");
  for (j = length - 1; j >= 0; j--)
  {
      printf("%d\n", arr[j]);
  }


  return 0;
}
