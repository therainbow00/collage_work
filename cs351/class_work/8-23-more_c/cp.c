#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc < 3) {
    fprintf(stderr, "Usage: cp <src> <dest>\n");
    return 1;
  }

  FILE *src = fopen(argv[1], "r");
  if (src == NULL) {
    perror("open source");
    return 1;
  }

  FILE *dest = fopen(argv[2], "w");
  if (dest == NULL) {
    perror("open dest");
    return 1;
  }

  int ch;

  while ( (ch = fgetc(src)) != EOF ) {
    fputc(ch, dest);
  }
  fclose(src);
  fclose(dest);

  return 0;
}
