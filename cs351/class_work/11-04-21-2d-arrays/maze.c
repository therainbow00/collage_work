#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

struct direction {
  int dx, dy;
} dirs[] = {
  { 0, -1}, // up
  { 1,  0}, // right
  { 0,  1}, // down
  {-1,  0}  // left
};

int R(int a, int b)
{
  int d = abs(a - b) + 1;
  int m = a < b? a: b;
  return m + (rand()%d);
}

int H, W;

void makemaze(int **maze, int x, int y)
{
  int d = R(0, 3);
  for(int i=0; i < 4; i++) {
    int mx = x + dirs[d].dx;
    int my = y + dirs[d].dy;
    int nx = x + dirs[d].dx*2;
    int ny = y + dirs[d].dy*2;
    if (nx < W && ny < H && nx > 0 && ny > 0) {
      if (maze[my][mx] == 1 && maze[ny][nx] == 1) {
	maze[my][mx] = maze[ny][nx] = 0;
	makemaze(maze, nx, ny);
      }
    }
    d = (d+1) % 4;
  }
}

void displaymaze(int **maze)
{
  clear();
  for(int r = 0; r < H; r++) {
    for(int c = 0; c < W; c++) {
      mvaddch(r, c, ' ' | (maze[r][c]? A_REVERSE : 0));
    }
  }
  refresh();
}

void pokeholes(int **maze)
{
  int count, x, y;
  for(int holes = 0; holes < 50; holes++) {
    do {
      do {
	x = R(1, W-2);
	y = R(1, H-2);
      } while (maze[y][x] == 0);
      count = 0;
      if (maze[y+1][x] && maze[y-1][x] && !maze[y][x+1] && !maze[y][x-1]) count++;
      if (maze[y][x+1] && maze[y][x-1] && !maze[y+1][x] && !maze[y-1][x]) count++;
    } while (count != 1);
    maze[y][x] = 0;
  }
}

void initmaze(int **maze)
{
  for(int r=0; r < H; r++) {
    for(int c=0; c < W; c++) {
      maze[r][c] = 1;
    }
  }
}

void shutdown(void)
{
  nocbreak();
  echo();
  endwin();
  exit(0);
}

int main(void)
{
  srand(time(0));
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  start_color();
  curs_set(0);
  nodelay(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_WHITE);

  H = LINES%2==0? LINES-1 : LINES;
  W = COLS%2==0? COLS-1 : COLS;

  int **maze = malloc(sizeof(int *) * H);

  for(int r=0; r < H; r++) {
    maze[r] = malloc(sizeof(int) * W);
    for(int c=0; c < W; c++) {
      maze[r][c] = 1;
    }
  }

  maze[1][1] = 0;
  makemaze(maze, 1, 1);
  pokeholes(maze);
  displaymaze(maze);

  int px = 1, py = 1, dir = -1;

  while (1) {
    mvaddch(py, px, ACS_DIAMOND | COLOR_PAIR(1) | A_BOLD);
    refresh();
    int ch = getch();
    switch(ch) {
      case 'q':
      case 'Q': shutdown();
      case 'w': case KEY_UP:	 dir=0; break;
      case 's': case KEY_DOWN:   dir=2;  break;
      case 'a': case KEY_LEFT:   dir=3; break;
      case 'd': case KEY_RIGHT:  dir=1;  break;
      case ' ': dir=-1; break;
    }
    if (dir != -1 && maze[py+dirs[dir].dy][px+dirs[dir].dx] == 0) {
      int nx = px + dirs[dir].dx;
      int ny = py + dirs[dir].dy;
      mvaddch(py, px, ' ');
      px = nx; py = ny;
    }
    usleep(100000);
  }

  return 0;
}
