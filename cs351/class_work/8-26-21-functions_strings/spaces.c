#include <stdio.h>
#include <stdlib.h>

#define K	1024

//'a', 'b', 'c', 'd', 'e', 'f', '\0', '\0', '?', '?', '?', '?', .... 1024, '?'

void trim(char s[])
{
  for(int i=0; s[i] != '\0'; i++)
    if (s[i] == '\n') {
      s[i] = '\0';
      break;
    }
}

int myisspace(char ch)
{
  if ((ch == ' ') || (ch == '\t')) return 1;
  return 0;
}

int countspaces(char s[])
{
  int count = 0;
  for(int i=0; s[i] != '\0'; i++)
    if (myisspace(s[i])) count++;
  return count;
}

int main(void)
{
  char str[K];

  printf("Input a string: ");
  if (fgets(str, K, stdin) == NULL) {
    perror("fgets");
    return 1;
  }
  trim(str);
  printf("The amount of whitespace in the string %d\n", countspaces(str));
  printf("The string is '%s'\n", str);

  return 1;
}
