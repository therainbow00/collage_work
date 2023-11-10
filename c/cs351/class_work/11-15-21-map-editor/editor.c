#include "editor.h"

void outline(int sx, int sy, int ex, int ey)
{
  int t;
  if (sx > ex) { t = sx; sx = ex; ex = t; }
  if (sy > ey) { t = sy; sy = ey; ey = t; }

  mvaddch(sy, sx, ACS_ULCORNER);
  mvaddch(ey, sx, ACS_LLCORNER);
  mvaddch(sy, ex, ACS_URCORNER);
  mvaddch(ey, ex, ACS_LRCORNER);
  for(int x = sx+1; x < ex; x++) {
    mvaddch(sy, x, ACS_HLINE);
    mvaddch(ey, x, ACS_HLINE);
  }
  for(int y = sy+1; y < ey; y++) {
    mvaddch(y, sx, ACS_VLINE);
    mvaddch(y, ex, ACS_VLINE);
  }
}

void display_map(cell_t **map, int sw, int sh, int w, int h, int xo, int yo)
{
  int x, y;
  for(int r=0; r < sh; r++) {
    y = r+yo;
    if (y >= h) break;
    for(int c=0; c < sw; c++) {
      x = c+xo;
      if (x >= w) break;
      int ch = map[y][x].ch;
      if (ch == 0) ch = '.';
      if (ch == 1) ch = '#';
      mvaddch(r+1, c+1, ch | COLOR_PAIR(map[y][x].color));
    }
  }
}


void editor(cell_t **map, int w, int h)
{
  int xoff = 0, yoff = 0, cx=0, cy=0;
  int ed_w = COLS - 22, ed_h = LINES - 2;

  while (1) {
    clear();
    outline(0, 0, ed_w+1, ed_h+1);
    display_map(map, ed_w, ed_h, w, h, xoff, yoff);
    mvprintw(1, ed_w + 4, "(%3d x %3d)", cx, cy);
    move((cy-yoff)+1, (cx-xoff)+1);

    refresh();
    int ch = waitforkeypress();
    if (ch == 'Q') break;
    switch(ch) {
      case 'w':
      case KEY_UP:
	if (cy-yoff <= 0) {
	  if (yoff) yoff--;
	  if (cy-yoff > 0) cy--;
	} else cy--;
	break;
      case 's':
      case KEY_DOWN:
	if ((cy-yoff) < ed_h-1) cy++;
	else {
	  if (cy+1 < h) {
	    cy++;
	    yoff++;
	  }
	}
	break;
      case 'a':
      case KEY_LEFT:
	if (cx-xoff <= 0) {
	  if (xoff) xoff--;
	  if (cx-xoff > 0) cx--;
	} else cx--;
	break;
      case 'd':
      case KEY_RIGHT:
	if ((cx-xoff) < ed_w-1) cx++;
	else {
	  if (cx+1 < w) {
	    cx++;
	    xoff++;
	  }
	}
	break;
      case ' ':
	if (cy < h && cx < w)
	  map[cy][cx].ch ^= 1;
    }
  }
}

int main(int argc, char *argv[])
{
  int map_width = 0, map_height = 0;
  cell_t **map = NULL;

  if (argc < 2) {
    printf("Usage: editor <mapfile>\n");
    return 1;
  }
  init_curses();

  map = load_map(argv[1], &map_width, &map_height);
  if (map == NULL) {
    ask_width_height(&map_width, &map_height);
    map = new_map(map_width, map_height);
  }
  clear();
  mvprintw(10, 10, "We have a %d x %d map.", map_width, map_height);
  waitforkeypress();

  editor(map, map_width, map_height);
  save_map(argv[1], map, map_width, map_height);

  leave_curses();
  return 0;
}
