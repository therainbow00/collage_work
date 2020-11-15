/*
  By Jeff Kinne, an example of using curses for a game
  where there is a map displayed and the user uses
  wasd keys to move.

  To Compile: gcc map.c -lncurses -o map

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curses.h>



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

/*
  Reading maze from file.
  0. Read from file and print on screen.
  1. Enforce rule that the dimensions in the file are same as this.
     You can getline into myMaze[i] for row i
  2. User option to choose which maze - by command-line argument.
 */

int myRow=1, myColumn=1;

char chTyped;


void reDisplay() {
  //char s[1000];
  int i;

  // mvprintw is like printf but you tell it where on the screen to print - 
  // which row and column.
  mvprintw(0,0,"Maze of doom..."); 

  // prints the maze
  for(i=0; i < NUM_ROWS; i++)
    mvprintw(2+i, 0, "%s", myMaze[i]);

  // print me.
  mvprintw(2 + myRow, myColumn, "@");

  mvprintw(20, 0, "Press q to quit.");

  mvprintw(21, 0, "Character just typed: %d", chTyped);

  refresh(); // make it redisplay based on what we've done.
}


int main(int argc, char *argv[]) {

  WINDOW * mainwin;
  mainwin = initscr(); // create the screen  
  noecho(); // don't display characters that are typed
  cbreak(); // don't wait for enter key for us to get characters

  if (mainwin == NULL) { // if there was an error
    printf("Error initializing screen with ncurses.\n");
    return 0;
  }


  // got stuff setup, so now display the screen.
  reDisplay();

  // now just read a character at a time until they want to quit.
  //scanf("%c",&ch); note: can use scanf if you want
  chTyped = getchar();
  while (chTyped != 'q') {
    // check if they place they're trying to go to is...
    // if M, then fight monster
    // if $, then collect gold
    if (chTyped == 'w' && myMaze[myRow-1][myColumn] == ' ') {
      myRow--;
    }
    if (chTyped == 's' && myMaze[myRow+1][myColumn] == ' ') {
      myRow++;
    }
    if (chTyped == 'a' && myMaze[myRow][myColumn-1] == ' ') {
      myColumn--;
    }
    if (chTyped == 'd' && myMaze[myRow][myColumn+1] == ' ') {
      myColumn++;
    }

    

    reDisplay();
    //scanf("%c",&ch);
    chTyped = getchar();
  }


  // before we quit, clean up the screen...  we'll leave it 
  // blank and nice.
  delwin(mainwin);
  endwin();
  refresh();
  return 0;
}
