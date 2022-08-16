#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define K	1024

int isdelim(char c, char *delim)
{
  while (*delim)
    if (c == *(delim++)) return 1;
  return 0;
}

char *mystrtok(char *str, char *delim)
{
  static char *p;
  char *s;

  if (str != NULL) p = str;

  while(*p && isdelim(*p,delim)) p++;
  if (*p == '\0') return NULL;

  s = p++;
  while(*p && !isdelim(*p,delim)) p++;
  if (*p) {
    *(p++) = '\0';
  }
  return s;
}

char **tokenize(char *line)
{
  char *delim = " ,\n";
  int cur = 0, max = 10;
  char **words = malloc(sizeof(char *) * max);

  char *word = mystrtok(line, delim);
  do {
    if (cur >= max-1) words = realloc(words, sizeof(char *) * (max += 10));
    words[cur++] = strcpy(malloc(strlen(word)+1), word);
  } while ((word = mystrtok(NULL, delim)));
  words[cur] = NULL;

  return words;
}

/**
 * Prints the words of a colon delimited string (argv[1]):
 */
int main(void)
{
  char buf[K+1];
  int r;

  while ( (r = read(STDIN_FILENO, buf, K)) > 0) {
    buf[r] = '\0';
    char **words = tokenize(buf);
    for(int i=0; words[i] != NULL; i++)
      printf("words[%d] = '%s'\n", i, words[i]);
  }

  return 0;
}
