#include "point.h"

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

int fgcolor = 1;

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
  ch.attr = COLOR_PAIR(fgcolor<<3 | COLOR_BLACK);
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
  screen[y>>1][x>>1] |= (1<<((y&1)<<1)) << (x&1);
  update(x, y);
}

void clrpoint(int x, int y)
{
  if (outofbounds(x, y)) return;
  screen[y>>1][x>>1] &= ~((1<<((y&1)<<1)) << (x&1));
  update(x, y);
}

void invert(int x, int y)
{
  if (outofbounds(x, y)) return;
  screen[y>>1][x>>1] ^= (1<<((y&1)<<1)) << (x&1);
  update(x, y);
}

void xline(int x1, int y1, int x2, int y2, void (*plotfunc)(int, int))
{
  float dx = (float)x2-(float)x1;
  float dy = (float)y2-(float)y1;
  float cx = (float)x1, cy = (float)y1;

  int d = sqrt(dx*dx + dy*dy);
  dx = dx / d;
  dy = dy / d;
  for(int i=0; i < d; i++) {
    plotfunc((int)cx, (int)cy);
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
  nodelay(stdscr, TRUE);
  // Setup colors:
  start_color();
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      init_pair(i*8+j, i, j);
  // Turn off the cursor:
  curs_set(0);
}

void circle(int cx, int cy, double r)
{
  for(int deg=0; deg < 360; deg++) {
    double rad = (M_PI/180.0)*(double)deg;
    int x = (int)(cos(rad) * r);
    int y = (int)(sin(rad) * r);
    plot(cx+x, cy+y);
  }
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
