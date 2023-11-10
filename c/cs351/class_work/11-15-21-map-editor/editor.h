#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>

typedef struct cell {
  int color;	// Curses color-pair (fgcolor<<3 | bgcolor)
  int ch;	// Character to display at this position
  int mob;	// Monster here?
} cell_t;

// io.c:
void ask_width_height(int *w, int *h);
int waitforkeypress(void);

// util.c:
cell_t **load_map(char *filename, int *map_width, int *map_height);
int save_map(char *filename, cell_t **map, int w, int h);
cell_t **new_map(int width, int height);
void init_curses(void);
void leave_curses(void);
