#include "hangman.h"

// Also strips newlines from the end of the old string:
char *my_strdup(char *old)
{
  int i, len = strlen(old) + 1;
  char *new = malloc(len);
  for(i=0; old[i] != '\0'; i++) {
    if (old[i] == '\n') break;
    new[i] = old[i];
  }
  new[i] = '\0';
  return new;
}

char **readfile(char *filename, int *size)
{
  int maxline = 100, nline = 0;
  char **line = calloc(maxline, sizeof(char *));
  char wordbuf[K];

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return NULL;
  }

  while (fgets(wordbuf, K, fp) != NULL) {
    if (nline >= maxline-2) line = realloc(line, sizeof(char *) * (maxline+=100));
    line[nline++] = my_strdup(wordbuf);
  }
  fclose(fp);
  line[nline] = NULL;
  *size = nline;

  return line;
}
