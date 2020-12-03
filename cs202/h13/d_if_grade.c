/*
  Programming concept: if and else, boolean conditions

  Program should:      ask user for a number grade (e.g., 95), print what the letter grade is (e.g., A)
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int num_grade;
  printf("Grade please (floating point #): ");
  scanf("%d", &num_grade);
  float f_num_grade = (float) num_grade;

  if (f_num_grade <= 100 && f_num_grade >= 93)
  {
      printf("A\n");
  }
  else if (f_num_grade <= 93 && f_num_grade >= 90)
  {
      printf("A-\n");
  }
  else if (f_num_grade <= 90 && f_num_grade >= 87)
  {
      printf("B+\n");
  }
  else if (f_num_grade <= 87 && f_num_grade >= 83)
  {
      printf("B\n");
  }
  else if (f_num_grade <= 83 && f_num_grade >= 80)
  {
      printf("B-\n");
  }
  else if (f_num_grade <= 80 && f_num_grade >= 77)
  {
      printf("C+\n");
  }
  else if (f_num_grade <= 77 && f_num_grade >= 73)
  {
      printf("C\n");
  }
  else if (f_num_grade <= 73 && f_num_grade >= 70)
  {
      printf("C-\n");
  }
  else if (f_num_grade <= 70 && f_num_grade >= 67)
  {
      printf("D+\n");
  }
  else if (f_num_grade <= 67 && f_num_grade >= 63)
  {
      printf("D\n");
  }
  else if (f_num_grade <= 63 && f_num_grade >= 60)
  {
      printf("D-\n");
  }
  else if (f_num_grade <= 60)
  {
      printf("F\n");
  }


  return 0;
}
