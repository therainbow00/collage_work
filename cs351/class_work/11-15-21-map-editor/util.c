#include "editor.h"

/*
width height
cell data row 0, col 0: color ch mob (one per line)
cell data row 0, col 1: color ch mob (one per line)
...
cell data row 0, col width-1: color ch mob (one per line)
cell data row 1, col 0: color ch mob (one per line)
...
*/

cell_t **load_map(char *filename, int *map_width, int *map_height)
{
  cell_t **map;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) return NULL;

  if (fscanf(fp, "%d %d", map_width, map_height) != 2) {
    leave_curses();
    fprintf(stderr,"Unable to get map width/height\n");
    exit(0);
  }
  map = malloc(sizeof(cell_t *) * (*map_height));
  for(int row = 0; row < *map_height; row++) {
    map[row] = malloc(sizeof(cell_t) * (*map_width));
    for(int col = 0; col < *map_width; col++) {
      if (fscanf(fp, "%d %d %d", &map[row][col].color, &map[row][col].ch, &map[row][col].mob) != 3) {
	leave_curses();
	fprintf(stderr,"Failed to read data for row %d, col %d\n", row, col);
	exit(0);
      }
    }
  }
  fclose(fp);
  return map;
}

int save_map(char *filename, cell_t **map, int w, int h)
{
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) return -1;

  fprintf(fp, "%d %d\n", w, h);
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      fprintf(fp, "%d %d %d\n", map[row][col].color, map[row][col].ch, map[row][col].mob);
    }
  }

  fclose(fp);
  return 0;
}

cell_t **new_map(int width, int height)
{
  cell_t **map;

  map = malloc(sizeof(cell_t *) * width);
  for(int row = 0; row < height; row++) {
    map[row] = malloc(sizeof(cell_t) * width);
    for(int col = 0; col < width; col++) {
      map[row][col].color = 0;
      map[row][col].ch = 0;
      map[row][col].mob = 0;
    }
  }
  return map;
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
//  curs_set(0);
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
