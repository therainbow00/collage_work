#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K   1024

/** (4pts)
 * Complete this function. It should return the files data as a single null
 * character terminated array of characters. It should read the file one
 * character at a time while allocating (and re-allocating) space for the the
 * file in 100 byte increments.
 */

char *readfile(FILE *fp)
{
    int maxline = 100, nline = 0, ch;
    char *line = malloc(maxline);

    while ((ch = fgetc(fp)) != EOF)
    {
      if (nline >= maxline) line = realloc(line, maxline += 100);
      line[nline++] = ch;
    }
    line[nline] = '\0';
    fclose(fp);
    return line;

}

/*
char *readfile(FILE *fp)
{
  int max = 100, idx = 0;
  int ch;
  char *buf = malloc(sizeof(char) * max);

  while ((ch = fgetc(fp)) != EOF) {
    if (idx >= max - 2) buf = realloc(buf, sizeof(char) * (max += 100));
    buf[idx++] = ch;
  }
  buf[idx] = '\0';
  return buf;
}
*/

/**
 * Do not modify this part of the program.
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: p1 <filename>\n");
    return 0;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  char *data = readfile(fp);
  printf("%s", data);

  return 0;
}
