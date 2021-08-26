#include <stdio.h>

int nums[] = { 5, 23, -6, 13, 100, 2, 19 };

void bubblesort(int a[], int len)
{
  int swapped;

  do {
    swapped = 0;

    for(int i = 1; i <= len-1; i++) {
      if (a[i-1] > a[i]) {
	int t = a[i];
	a[i] = a[i-1];
	a[i-1] = t;
	swapped = 1;
      }
    }
  } while (swapped);
}

int main(void)
{
  int numslen = sizeof(nums) / sizeof(int);

  for(int i = 0; i < numslen; i++) {
    printf("%d%c", nums[i], (i==numslen-1)? '\n': ',');
  }
  bubblesort(nums, numslen);
  for(int i = 0; i < numslen; i++) {
    printf("%d%c", nums[i], (i==numslen-1)? '\n': ',');
  }

  return 0;
}
