#include "point.h"


int main(void)
{
  init_curses();
  screen_init();

  path_t *path = beginPath(CONNECTED);
  moveTo(path, 20,0);
  lineTo(path, -20,10);
  lineTo(path, -16,7);
  lineTo(path, -16,-7);
  lineTo(path, -20,-10);

  stroke(path);

  refresh();
  int ch;
  do {
    ch = getch();
    usleep(10000);
  } while (ch != 'q');
  leave_curses();
}
