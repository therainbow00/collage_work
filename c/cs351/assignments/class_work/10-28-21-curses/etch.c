#include <stdio.h>
#include <curses.h>

// Compile with:
// gcc -o etch-a-sketch etch-a-sketch.c -lncurses

int main(void)
{
  initscr();
  // Disables echo of keys typed:
  noecho();
  // Turns off line buffering (so we can get key-presses immediately):
  cbreak();
  // Enable arrow keys:
  keypad(stdscr, TRUE);

  // Define our software cursor position:
  int x = 1, y = 1;
  // Clears the screen:
  clear();

  // Draws a nice box around the entire screen:
  border(0,0,0,0,0,0,0,0);

  // moves the cursor to (1,1):
  move(y,x);
  refresh();

  // Loops forever (a non-zero number is always "true"):
  while (1) {
    // Read a character from curses:
    int ch = getch();
    // Exit the loop on a 'q' or 'Q':
    if (ch == 'q' || ch == 'Q') break;
    // Clear the screen when a 'c' or 'C' is typed:
    if (ch == 'c' || ch == 'C') {
      // Clearing the screen, moves the cursor back to 0,0:
      clear();
      // Restore the cursor to where it should be:
      move(y,x);
      refresh();
      continue;
    }
    // Check for movement keys and update y,x, making sure the coordinates stay
    // inside of the screen
    if (ch == KEY_UP || ch == 'w') {
      if (y > 0) y--;
    }
    if (ch == KEY_DOWN || ch == 's') {
      if (y < LINES-1) y++;
    }
    if (ch == KEY_LEFT || ch == 'a') {
      if (x > 0) x--;
    }
    if (ch == KEY_RIGHT || ch == 'd') {
      if (x < COLS-1) x++;
    }
    // Adds "reversed" space character at the cursor position, we'll talk about
    // "attributes" like A_REVERSE next time.
    addch(' '|A_REVERSE);
    // addch moves the cursor forward, so put the cursor back:
    move(y,x);
    refresh();
  }

  // Shutdown:
  echo();
  nocbreak();
  endwin();
  return 0;
}
