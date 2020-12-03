/*
  Programming concept: read from user

  Program should:      ask user for first name, ask for last name, print hello
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

  char first[100];
  printf("Hello.  First name please: ");
  scanf("%99s", first);

  char last[100];
  printf("Last name please: ");
  scanf("%99s", last);

  printf("Hello %s %s!\n", first, last);
  
  return 0;
}
