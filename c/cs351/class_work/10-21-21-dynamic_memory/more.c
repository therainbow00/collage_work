#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN	4096

int main(int argc, char *argv[])
{
  // A "C" file pointer:
  FILE *fp = stdin;

  if (argc > 1) {
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      perror("fopen");
      return 1;
    }
  }

  int nlines = 10, line = 0;
  char **data = malloc(sizeof(char *) * nlines);
  char buf[MAXLEN];

  while(fgets(buf, MAXLEN, fp) != NULL) {
    if (line >= nlines-1) data = realloc(data, sizeof(char *) * (nlines+=10));
    data[line] = strdup(buf);
    line++;
  }

  for(int i=0; i < line; i++) {
    for(int j=0; data[i][j] != '\0'; j++) {
      fputc(toupper(data[i][j]), stderr);
      usleep(33333); // 300 baud (300bps)
//      usleep(4166);	// ~2400bps
//      usleep(52);	// ~19200bps
//      usleep(17);	// ~57600bps
    }
  }

  fclose(fp);
  return 0;
}
