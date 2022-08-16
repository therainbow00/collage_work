#include <unistd.h>
#include <stdlib.h>

int my_strlen(char s[])
{
  int len = 0;
  while(s[len] != '\0') len++;
  return len;
}

int main(int argc, char *argv[])
{
  for(int i=0; i < argc; i++) {
    write(STDOUT_FILENO, argv[i], my_strlen(argv[i]));
    write(STDOUT_FILENO, "\n", 1);
  }
  exit(0);
}
