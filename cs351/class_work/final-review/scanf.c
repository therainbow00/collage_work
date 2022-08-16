#include <stdio.h>
#include <stdlib.h>

int *numbers(int *size)
{
  int idx = 0, max = 10;
  int *nums = malloc(sizeof(int) * max);
  int value;

  while (scanf("%d", &value) == 1) {
    if (idx >= max-1) nums = realloc(nums, sizeof(int) * (max += 10));
    nums[idx] = value;
    idx++;
  }
  *size = idx;

  return nums;
}

int main(void)
{
  int *nums, nnums;

  printf("Enter some numbers:\n");
  nums = numbers(&nnums);
  for(int i=0; i < nnums; i++) {
    printf("%d: %d\n", i, nums[i]);
  }

  return 0;
}
