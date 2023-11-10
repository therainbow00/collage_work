#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define MAXLEN	32768

char *strdup_trim(char *s)
{
  char *save, *m = malloc(len+1);

  for(save = m; *m = *s; m++, s++) {
    if (*s == '\n') break;
  }
  *m = '\0';

  return save;
}

char **readfile(FILE *fp)
{
  int nlines = 10, line = 0;
  char **data = malloc(sizeof(char *) * nlines);
  char buf[MAXLEN];

  while(fgets(buf, MAXLEN, fp) != NULL) {
    if (line >= nlines-1) data = realloc(data, sizeof(char *) * (nlines+=10));
    data[line] = strdup_trim(buf);
    line++;
  }
  return data;
}

int main(int argc, char *argv[])
{
  FILE *fp = stdin;

  if (argc > 1) {
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      perror("open");
      return 1;
    }
  }

  char **data = readfile(fp);
  fclose(fp);

  initscr();
  noecho();
  cbreak();

  int start = 0, line, offset = 0;
  while (1) {
    clear();

    line = start;
    for(int scrline = 0; data[line] != NULL && scrline < LINES-1; scrline++, line++) {
      if (strlen(data[line]) > offset)
        mvprintw(scrline, 0, "%.*s", COLS-1, data[line] + offset);
      if (strlen(data[line]) > COLS-1) {
	addch(ACS_DIAMOND | A_BOLD);
      }
    }

    attron(A_REVERSE);
    mvprintw(LINES-1, 0, "MORE?");
    attroff(A_REVERSE);
    int ch = getch();
    if (ch == 'q' || ch == 'Q') break;
    switch(ch) {
      case ' ':
	start = line;
	break;
      case 's':
      case '\n':
	if (data[start] == NULL) break;
	if (data[start+1] == NULL) break;
	start++;
	break;
      case 'w':
	if (start) start--;
	break;
      case 'd':
	offset++;
	break;
      case 'a':
	if (offset) offset--;
	break;
    }
  }

  nocbreak();
  echo();
  endwin();
}
