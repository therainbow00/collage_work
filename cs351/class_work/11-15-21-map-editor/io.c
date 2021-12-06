#include "editor.h"

void ask_width_height(int *w, int *h)
{
  nodelay(stdscr, FALSE);
  curs_set(1);
  echo();
  clear();
  mvprintw(10, 10, " Map width? ");
  scanw("%d", w);
  mvprintw(11, 10, "Map height? ");
  scanw("%d", h);
  nodelay(stdscr, TRUE);
  noecho();
  curs_set(0);
}

int waitforkeypress(void)
{
  int ch;
  do {
    usleep(10000);
    ch = getch();
  } while (ch == ERR);
  return ch;
}
