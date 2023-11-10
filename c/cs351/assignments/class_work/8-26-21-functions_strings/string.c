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

int mystrlen(char s[])
{
  int len;
  for(len=0; *s != '\0'; len=len+1) s++;
  return len;
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
  printf("The string read was %d bytes big.\n", mystrlen(str));
  printf("The string is '%s'\n", str);

  return 1;
}
