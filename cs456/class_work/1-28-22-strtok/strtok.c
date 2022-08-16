#include <stdio.h>
#include <string.h>

/**
 * Prints the words of a colon delimited string (argv[1]):
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: strtok <string>\n");
    return 1;
  }

  char *word = strtok(argv[1], ":");
  do {
    printf("Word = '%s'\n", word);
  } while ((word = strtok(NULL, ":")));

  return 0;
}
