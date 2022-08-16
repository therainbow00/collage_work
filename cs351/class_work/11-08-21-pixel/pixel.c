#define _XOPEN_SOURCE   500
#define NCURSES_WIDECHAR        1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <ncursesw/curses.h>

#define min(a, b)	((a)<(b)?(a):(b))

wchar_t pixels[] = {
  L' ', L'▘', L'▝', L'▀', L'▖', L'▌', L'▞', L'▛',
  L'▗', L'▚', L'▐', L'▜', L'▄', L'▙', L'▟', L'█'
};

/*
 \x 0 1
y \----
0 | 1 2
1 | 4 8
*/

int SCREEN_H, SCREEN_W;

int **screen;

void clrscreen(void)
{
  for(int y = 0; y < SCREEN_H; y++)
    for(int x = 0; x < SCREEN_W; x++)
      screen[y][x] = 0;
  clear();
}

void screen_init(void)
{
  screen = malloc(sizeof(int *) * (LINES+1));
  for(int row = 0; row < LINES; row++) {
    screen[row] = malloc(sizeof(int) * (COLS+1));
  }
  SCREEN_H = LINES;
  SCREEN_W = COLS;
  clrscreen();
  clear();
}

void update(int x, int y)
{
  cchar_t ch;
  int row = y>>1, col = x>>1;
//  ch.attr = COLOR_PAIR(2);
  ch.chars[0] = pixels[screen[row][col]];
  ch.chars[1] = 0;
  ch.ext_color = 0;
  mvadd_wch(row, col, &ch);
}

int outofbounds(int x, int y)
{
  if (x < 0 || x >= SCREEN_W*2) return 1;
  if (y < 0 || y >= SCREEN_H*2) return 1;
  return 0;
}

void plot(int x, int y)
{
  if (outofbounds(x, y)) return;
  screen[y>>1][x>>1] |= ((y&1)? 4 : 1) << (x&1);
  update(x, y);
}

void clrpoint(int x, int y)
{
  if (outofbounds(x, y)) return;
  screen[y>>1][x>>1] &= ~(((y&1)? 4 : 1) << (x&1));
  update(x, y);
}

void invert(int x, int y)
{
  if (outofbounds(x, y)) return;
  screen[y>>1][x>>1] ^= ((y&1)? 4 : 1) << (x&1);
  update(x, y);
}

void line(int x1, int y1, int x2, int y2)
{
  float dx = (float)x2-(float)x1;
  float dy = (float)y2-(float)y1;
  float cx = (float)x1, cy = (float)y1;

  int d = sqrt(dx*dx + dy*dy);
  mvprintw(0, 0, "dx = %f, dy=%f, d = %d\n", dx, dy, d);
  dx = dx / d;
  dy = dy / d;
  for(int i=0; i < d; i++) {
    plot((int)cx, (int)cy);
    cx += dx;
    cy += dy;
  }
}

/**
 * All the normal curses setup stuff
 */
void init_curses(void)
{
  setlocale(LC_ALL, "en_US.utf-8");
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
//  nodelay(stdscr, TRUE);
  // Setup colors:
  start_color();
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      init_pair(i*8+j, i, j);
  // Turn off the cursor:
  curs_set(0);
}

/**
 * Shuts curses down
 */
void leave_curses(void)
{
  curs_set(1);
  echo();
  nocbreak();
  endwin();
}

int main(void)
{
  init_curses();
  screen_init();

  int mx = SCREEN_W, my = SCREEN_H;
  double radius = min(SCREEN_W, SCREEN_H);
//  mvprintw(0,0,"%d x %d / %d\n", SCREEN_W, SCREEN_H, radius);

  // Circle:
//   for(int deg=0; deg < 360; deg++) {
//     double rad = (M_PI/180.0)*(double)deg;
//     int x = (int)(cos(rad) * radius);
//     int y = (int)(sin(rad) * radius);
//     plot(mx+x, my+y);
//   }

  line(10, 0, 25, 30);

  refresh();
  getch();
  leave_curses();
}
