/*
  Programming concept: reading file, command-line argument

  Program should:      take each command-line argument as the name of a file, for each open the file for reading, read the entire contents of the file and print

 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc > 0)
  {
      FILE *f;
      char s[101], c;
      f = fopen(argv[1], "r");
      if (f == NULL)
      {
          printf("No file.\n");
      }
      else
      {
          for (c = fgetc(f); c != EOF; c = fgetc(f))
          {
              printf("%c", c);
          }
          fclose(f);
      }
  }
  else if (argc <= 0)
  {
      printf("No file detected\n");
  }


  return 0;
}
