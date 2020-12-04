/*
  Programming concept: read through an array and do something for each item

  Program should:      read 10 numbers from user into an array, compute the average of the numbers, loop through the array again to count how many are greater than the average, print that count
 */

#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int arr[11], i, count = 0, greater_average = 0, j;
  float average;
  size_t length = (sizeof(arr) / sizeof(int)) - 1;

  for (i = 0; i < length; i++)
  {
      printf("Int please: ");
      scanf("%d", &arr[i]);
      count += arr[i];
  }
  average = (float) count / (float) length;
  printf("average is %lf\n", average);

  for (j = 0; j < length; j++)
  {
      if (arr[j] > average)
      {
          greater_average++;
      }
  }
  printf("%d of the #s were > than the average.\n", greater_average);

  return 0;
}
