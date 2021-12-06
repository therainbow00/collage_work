lines: lines.c
	$(CC) -o lines lines.c $(LIBS)
    #define _XOPEN_SOURCE   500
    #define NCURSES_WIDECHAR        1
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <locale.h>
    #include <math.h>
    #include <ncursesw/curses.h>

    #define min(a, b)	((a)<(b)?(a):(b))


    typedef enum { CONNECTED, UNCONNECTED } flag_t;

    typedef struct point {
      float x, y;
      flag_t flag;
      struct point *next;
    } point_t;

    typedef struct path {
      int flag;
      struct point *start, *end;
    } path_t;


    // path.c:
    path_t *beginPath(int flag);
    void moveTo(path_t *path, float x, float y);
    void lineTo(path_t *path, float x, float y);
    void stroke(path_t *path);

    // point.c
    void clrscreen(void);
    void screen_init(void);
    void update(int x, int y);
    void plot(int x, int y);
    void clrpoint(int x, int y);
    void invert(int x, int y);
    void xline(int x1, int y1, int x2, int y2, void (*plotfunc)(int, int));
    void init_curses(void);
    void circle(int cx, int cy, double r);
    void leave_curses(void);
