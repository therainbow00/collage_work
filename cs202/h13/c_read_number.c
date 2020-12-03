/*
  Programming concept: read a number from the user

  Program should:      ask the user for a number, print out what 2x and 3x the number are
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int num;
  printf("Enter a number please: ");
  scanf("%d", &num);

  printf("2x the number of %d is: %d\n", num, num * 2);
  printf("3x the number of %d is: %d\n", num, num * 3);

  return 0;
}
