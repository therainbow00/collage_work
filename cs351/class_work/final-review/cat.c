#include <stdio.h>

void cat(FILE *fp)
{
  int ch;

  while ((ch = fgetc(fp)) != EOF) {
    fputc(ch, stdout);
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2) cat(stdin);
  else {
    FILE *fp;
    for(int i=1; i < argc; i++) {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {
	perror("fopen");
	continue;
      }
      cat(fp);
      fclose(fp);
    }
  }

  return 0;
}
