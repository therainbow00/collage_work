/*
  Programming concept: read a number from the user

  Program should:      ask the user for a number, print out what 2x and 3x the number are
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int num;
  printf("Number please (floating point): ");
  scanf("%d", &num);
  float f_num = (float) num;

  printf("2 * %.2lf = %.2lf\n", f_num, f_num * 2);

  return 0;
}
