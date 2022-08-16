#include "hangman.h"


char *pickword(char **words, int nwords)
{
  int word = rand() % nwords;
  return words[word];
}

int display_word(char *word, char *guessed)
{
  int hstart = 30 - strlen(word), won = 1;

  move(12, hstart);
  for(int i = 0; word[i] != '\0'; i++) {
    if (strchr(guessed, word[i]) == NULL) {
      addch(' ' | A_UNDERLINE);
      won = 0;
    } else addch(word[i] | A_UNDERLINE);
    addch(' ');
  }
  return won;
}

void display_cowboy(int state)
{
   move(2, 29);
   addch(ACS_ULCORNER);
   for(int i=0; i < 7; i++) addch(ACS_HLINE);
   addch(ACS_URCORNER);
   for(int i=0; i < 7; i++) mvaddch(3+i, 29, ACS_VLINE);
   mvaddch(3, 37, ACS_VLINE);
   for(int i=0; i < 7; i++) mvaddch(10, 26+i, ACS_HLINE);
   mvaddch(10, 29, ACS_BTEE);

//    if (state == 0) return;
//    mvaddch(4, 37, 'O');
//    if (state == 1) return;
//    mvaddch(5, 37, ACS_VLINE);
//    mvaddch(6, 37, ACS_VLINE);
//    if (state == 2) return;
//    mvaddch(5, 36, '/');
//    if (state == 3) return;
//    mvaddch(5, 38, '\\');
//    if (state == 4) return;
//    mvaddch(7, 36, '/');
//    if (state == 5) return;
//    mvaddch(7, 38, '\\');

   switch(state) {
     case 6: mvaddch(7, 38, '\\');
     case 5: mvaddch(7, 36, '/');
     case 4: mvaddch(5, 38, '\\');
     case 3: mvaddch(5, 36, '/');
     case 2: mvaddch(5, 37, ACS_VLINE); mvaddch(6, 37, ACS_VLINE);
     case 1: mvaddch(4, 37, 'O');
   }
}

int play(char *word, int wins, int losses)
{
  int state = 0, gpos = 0;
  char guessed[26] = "";
  while (state <= 5) {
    clear();
    display_cowboy(state);
    mvprintw(0, 1, "Score: %d wins / %d losses", wins, losses);
    mvprintw(14, 4, "Guessed: %s", guessed);
    if (display_word(word, guessed)) break;
    refresh();
    int ch = getch();

    if (strchr(guessed, ch) != NULL) continue;
    guessed[gpos++] = ch;
    guessed[gpos] = '\0';
    if (strchr(word, ch) == NULL) state++;
  }
  display_cowboy(state);
  refresh();
  if (state > 5) return 0;
  return 1;
}

int main(void)
{
  int nwords;
  char mesg[100], **words = readfile("/mnt/c/Users/mattm/onedrive/desktop/coding/atom/collage_work/cs351/class_work/hangman/text.txt", &nwords);
  if (words == NULL) return 1;

  srand(time(NULL));

  initscr();
  if (LINES < 15 || COLS < 60) {
    nocbreak();
    echo();
    endwin();
    printf("Window is too small, it must at least 60 x 15\n");
    return 1;
  }
  noecho();
  cbreak();

  int wins = 0, losses = 0;

  while(1) {
    char *word = pickword(words, nwords);

    if (play(word, wins, losses)) {
      sprintf(mesg, "You won!");
      wins++;
    } else {
      sprintf(mesg, "You lost! The word was %s", word);
      losses++;
    }
    mvprintw(11, 30 - strlen(mesg)/2, "%s", mesg);
    mvprintw(15, 0, "Press any key to continue");
    getch();
  }

  nocbreak();
  echo();
  endwin();
  return 0;
}
