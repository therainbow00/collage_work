#include <curses.h>
#include <string.h>

// Compile with:
// gcc -o form form.c -lncurses

// Prints the string in 'mesg' in the center of the given 'line':
void center(int line, char mesg[]) {
  mvprintw(line, COLS/2-strlen(mesg)/2, mesg);
}

int main(void)
{
  int y, x;

  initscr();
  clear();

  // Reads the X and Y coordinates from the user:
  mvprintw(10,10, "Input X: ");
  scanw("%d", &x);
  mvprintw(11,10, "Input Y: ");
  scanw("%d", &y);

  clear();
  // Note that the y coordinate (the line) is always specified before the x
  // coordinate (the column) in curses functions that take coordinates:
  mvprintw(y, x, " <- %d,%d is there", x, y);

  center(LINES-1, "Press any key to exit");
  move(y, x);
  refresh();

  // Wait for the user to type a character:
  getch();

  endwin();
  return 0;
}
