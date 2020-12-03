/*
  Programming concept: if and else, boolean conditions

  Program should:      ask user for a number grade (e.g., 95), print what the letter grade is (e.g., A)
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int num_grade;
  printf("Enter a number grade: ");
  scanf("%d", &num_grade);

  if (num_grade <= 100 && num_grade >= 93)
  {
      printf("Letter grade: A\n");
  }
  else if (num_grade <= 93 && num_grade >= 90)
  {
      printf("Letter grade: A-\n");
  }
  else if (num_grade <= 90 && num_grade >= 87)
  {
      printf("Letter grade: B+\n");
  }
  else if (num_grade <= 87 && num_grade >= 83)
  {
      printf("Letter grade: B\n");
  }
  else if (num_grade <= 83 && num_grade >= 80)
  {
      printf("Letter grade: B-\n");
  }
  else if (num_grade <= 80 && num_grade >= 77)
  {
      printf("Letter grade: C+\n");
  }
  else if (num_grade <= 77 && num_grade >= 73)
  {
      printf("Letter grade: C\n");
  }
  else if (num_grade <= 73 && num_grade >= 70)
  {
      printf("Letter grade: C-\n");
  }
  else if (num_grade <= 70 && num_grade >= 67)
  {
      printf("Letter grade: D+\n");
  }
  else if (num_grade <= 67 && num_grade >= 63)
  {
      printf("Letter grade: D\n");
  }
  else if (num_grade <= 63 && num_grade >= 60)
  {
      printf("Letter grade: D-\n");
  }
  else if (num_grade <= 60)
  {
      printf("Letter grade: F\n");
  }


  return 0;
}
