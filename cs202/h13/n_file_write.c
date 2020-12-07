/*
  Programming concept: reading, writing to files, command-line arguments

  Program should:      assume three command line arguments that are file names, open the first for reading, open the second for writing, open the third for appending, read the entire contents of the first and write to the second and third.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc > 0)
  {
      FILE *f1, *f2, *f3;

      f1 = fopen(argv[1], "r");
      f2 = fopen(argv[2], "w");
      f3 = fopen(argv[3], "a");

      char c;
      if (f1 == NULL)
      {
          printf("There is no file name for argument 1.\n");
          exit(0);
      }
      else if (f2 == NULL)
      {
          printf("There is no file name for argument 2.\n");
          exit(0);
      }
      else if (f3 == NULL)
      {
          printf("There is no file name for argument 3.\n");
          exit(0);
      }
      else
      {
          while ((c = fgetc(f1)) != EOF)
          {
              fprintf(f2, "%c", c);
              fprintf(f3, "%c", c);
          }
          fclose(f3);
          fclose(f2);
          fclose(f1);
      }

  }

  return 0;
}
