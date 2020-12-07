/*
  Programming concept: 2d arrays

  Program should:      declare a 2d array of integers that is 5x5, use nested loops to ask for the 25 values and put them into the array, then ask the user for a row and column and print out the value from the array at that row and column

 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[5][5], row_col[3], i, j, h, c, b;
  for (i = 0; i < 5; i++)
  {
      printf("5 intergers please: ");
      for (int j = 0; j < 5; j++)
      {
          scanf("%d", &arr[i][j]);
      }
  }

  printf("row and col please (each 0 - 4): ");
  for (h = 0; h < (sizeof(row_col) / sizeof(int) - 1); h++)
  {
      scanf("%d", &row_col[h]);
  }

  for (c = 0; c < ((sizeof(arr) / sizeof(int)) / 5); c++)
  {
      for (b = 0; b < ((sizeof(arr) / sizeof(int)) / 5); b++)
      {
          if (row_col[0] == c && row_col[1] == b)
          {
              printf("value at that row and col is %d\n", arr[c][b]);
          }
      }
  }

  return 0;
}
