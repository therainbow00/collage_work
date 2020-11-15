/*
  By Jeff Kinne, an example to show how to make something
  automatically move in curses, have something move based
  on wasd keys, and leave a trail on the screen.

  To Compile: gcc ball.c -lncurses -o ball

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curses.h>


int myRow=1, myColumn=1;

int ballRow= 1, ballColumn = 40;

char chTyped;


void reDisplay() {
  // print me.
  mvprintw(myRow, myColumn, "@");

  mvprintw(ballRow, ballColumn, "O");
  
  mvprintw(20, 0, "Press q to quit.");
  mvprintw(21, 0, "Character just typed: %d", chTyped);

  refresh(); // make it redisplay based on what we've done.
}


int main(int argc, char *argv[]) {

  WINDOW * mainwin;
  mainwin = initscr(); // create the screen  
  noecho(); // don't display characters that are typed
  cbreak(); // don't wait for enter key for us to get characters
  halfdelay(1); // make getch return after 1/10 of a second, even if no character typed
  
  if (mainwin == NULL) { // if there was an error
    printf("Error initializing screen with ncurses.\n");
    return 0;
  }


  // got stuff setup, so now display the screen.
  reDisplay();

  // now just read a character at a time until they want to quit.
  //scanf("%c",&ch); note: can use scanf if you want
  chTyped = getch();
  int direction = 1;
  while (chTyped != 'q') {
    mvprintw(ballRow, ballColumn, " "); // erase where ball was
  
    ballRow += direction;
    if (ballRow > 25) direction *= -1;
    if (ballRow < 0) direction *= -1;
    
    if (chTyped == 'w') {
      myRow--;
    }
    if (chTyped == 's') {
      myRow++;
    }
    if (chTyped == 'a') {
      myColumn--;
    }
    if (chTyped == 'd') {
      myColumn++;
    }
    if (myRow < 0) myRow = 0;
    if (myColumn < 0) myColumn = 0;
    if (myRow > 24) myRow = 24;
    if (myColumn > 79) myColumn = 79;

    reDisplay();
    //scanf("%c",&ch);
    chTyped = getch();
  }


  // before we quit, clean up the screen...  we'll leave it 
  // blank and nice.
  delwin(mainwin);
  endwin();
  refresh();
  return 0;
}
