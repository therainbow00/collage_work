/*
  Programming concept: while loop

  Program should:      ask user for the answer, keep asking until they type 42
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  char response[6], correct[] = "42";
  printf("What is the answer (a string)? ");
  scanf("%5s", response);

  while (strcmp(response, correct) != 0)
  {
      printf("What is the answer (a string)? ");
      scanf("%5s", response);
  }
  printf("Yes, indeed.\n");

  return 0;
}
