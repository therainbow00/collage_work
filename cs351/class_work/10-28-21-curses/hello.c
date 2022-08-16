#include <curses.h>
#include <string.h>

// Compile with:
// gcc -o curses_hello curses_hello.c -lncurses

int main(void)
{
  // Define our message and it's "width" in characters:
  char *message = "Hello, world!";
  int mesglen = strlen(message);

  // Initialize curses:
  initscr();
  // Clear the virtual screen:
  clear();

  // Print the message in the middle of the virtual screen:
  // The message is centered on the line by subtracting half the width of the
  // message from the middle column of the screen:
  mvprintw(LINES/2, (COLS/2)-(mesglen/2), "%s", message);
  // Updates the screen to look like the virtual screen:
  refresh();

  // Wait for a key-press (get a character from the user.)
  //getch();
  // Shutdown curses:
  endwin();
  return 0;
}
