/*
  By Jeff Kinne, an example of using curses for a game
  where there is a map displayed and the user uses
  wasd keys to move.

  To Compile: gcc map.c -lncurses -o map

  Note - this is a modified version of map.c that does some extra things.
  Modifications are marked in the file with MOD
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curses.h>

#include <time.h> // MOD
#include <ctype.h> // MOD


// location - two coordinates, row and column, integers
// the map  - strings for each row of the screen
// monsters
// etc.

//char s[100] = "hello";

// note: we need to put the \0 in ourselves when we have
// an array of strings."
#define NUM_ROWS 9
char myMaze[NUM_ROWS][12] = {
  "***********\0",  // myMaze[0]
  "*         *\0",  // myMaze[1]
  "* ** ***  *\0",
  "*    *    *\0",
  "**** ***  *\0",
  "*         *\0",
  "*         ~\0",
  "* $ M     *\0",
  "***********\0",  // myMaze[7]
};

char myMaze2[NUM_ROWS][12] = {
  "***********\0",  // myMaze[0]
  "*         *\0",  // myMaze[1]
  "*         *\0",
  "*         *\0",
  "*         *\0",
  "*         *\0",
  "*         *0",
  "* $ M     *\0",
  "***********\0",  // myMaze[7]
};

int level = 1;

/*
  Reading maze from file.
  0. Read from file and print on screen.
  1. Enforce rule that the dimensions in the file are same as this.
     You can getline into myMaze[i] for row i
  2. User option to choose which maze - by command-line argument.
 */

int myRow=1, myColumn=1;

int chTyped; // MOD.  To get KEY_UP, etc. needs to be an int

// MOD
typedef enum {COL_NORMAL=1, COL_HIGHLIGHT=2} MY_COLOR_PAIRS;

// MOD.  initialize some things
void init() {
  start_color();
  init_pair(COL_NORMAL, COLOR_YELLOW, COLOR_BLACK);
  init_pair(COL_HIGHLIGHT, COLOR_CYAN, COLOR_BLACK);

  srand(clock());
}


void reDisplay() {
  // MOD, if you want to erase the screen before redrawing it
  //erase();
  
  //char s[1000];
  int i;

  // mvprintw is like printf but you tell it where on the screen to print - 
  // which row and column.
  mvprintw(0,0,"Maze of doom..."); 

  // prints the maze
  attron(COLOR_PAIR(COL_NORMAL)); // MOD
  for(i=0; i < NUM_ROWS; i++)
    mvprintw(2+i, 0, "%s", myMaze[i]);
  attroff(COLOR_PAIR(COL_NORMAL)); // MOD

  // print me.
  attron(COLOR_PAIR(COL_HIGHLIGHT)); // MOD
  mvprintw(2 + myRow, myColumn, "@");
  attroff(COLOR_PAIR(COL_HIGHLIGHT)); // MOD

  mvprintw(20, 0, "Press q to quit.");

  mvprintw(21, 0, "Character just typed: %d", chTyped);

  refresh(); // make it redisplay based on what we've done.
}

// MOD.
int doMonster() {
  int heads = rand() % 2;

  mvprintw(15, 0, "Monster monster.  Guess, heads or tails: ");
  mvprintw(16, 0, "  (cheat mode, heads=%d) ", heads);
  nocbreak(); echo(); // show keys pressed for now
  refresh();
  char s[100];
  scanw("%99s", s);

  cbreak(); noecho(); // go back to not showing keys pressed

  
  if ((heads && tolower(s[0]) == 'h') ||
      (!heads && tolower(s[0]) == 't')) {
    mvprintw(15, 0, "Good job, you defeat the monster.      ");
    return 1;
  }
  else {
    mvprintw(15, 0, "Tough luck, you have been injured.     ");
    return 0;
  }
}

int main(int argc, char *argv[]) {
  WINDOW * mainwin;
  mainwin = initscr(); // create the screen  
  noecho(); // don't display characters that are typed
  cbreak(); // don't wait for enter key for us to get characters
  
  keypad(mainwin, TRUE); // MOD.  make it so can use arrows as well, with KEY_UP, KEY_LEFT, etc.
  
  if (mainwin == NULL) { // if there was an error
    printf("Error initializing screen with ncurses.\n");
    return 0;
  }

  // note that init'ing colors should be done after initscr
  init(); // MOD

  // got stuff setup, so now display the screen.
  reDisplay();

  // now just read a character at a time until they want to quit.
  //scanf("%c",&ch); note: can use scanf if you want
  chTyped = getch(); // MOD.  note: use getch instead of getchar if you want to use the arrow keys
  while (chTyped != 'q') {
    // check if they place they're trying to go to is...
    // if M, then fight monster
    // if $, then collect gold
    
    // MOD this section...
    int newRow = myRow, newColumn = myColumn;
    if (chTyped == 'w' || chTyped == KEY_UP) newRow--;
    if (chTyped == 's' || chTyped == KEY_DOWN) newRow++;
    if (chTyped == 'a' || chTyped == KEY_LEFT) newColumn--;
    if (chTyped == 'd' || chTyped == KEY_RIGHT) newColumn++;

    switch (myMaze[newRow][newColumn]) {
    case ' ':
      myRow = newRow; myColumn = newColumn;
      break;
    case '$':
      // do something, like remove the $ from the map
      myMaze[newRow][newColumn] = ' ';
      myRow = newRow; myColumn = newColumn;
      break;
    case 'M':
      doMonster();
      break;
    }

    

    reDisplay();
    chTyped = getch(); // MOD.  use getch to be able to get KEY_UP, etc.
  }


  // before we quit, clean up the screen...  we'll leave it 
  // blank and nice.
  delwin(mainwin);
  endwin();
  refresh();
  return 0;
}
