#include <stdio.h>

/**
 * argc = The count of words on the command line, including the command itself.
 * argv = The vector (array) of strings representing the words of the command
 *        line.  Terminated by a NULL pointer at the end of the array.
 */
int main(int argc, char *argv[])
{
  int i;
  printf("argc = %d\n", argc);
  for(i = 0; i < argc; i++) {
    printf("argv[%d] = \"%s\"\n", i, argv[i]);
  }
  printf("argv[%d] = NULL\n", i);

  return 0;
}
