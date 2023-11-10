#include "point.h"

path_t *beginPath(int flag)
{
  path_t *p = malloc(sizeof(path_t));
  p->flag = flag;
  p->start = p->end = NULL;
  return p;
}

void moveTo(path_t *path, float x, float y)
{
  point_t *pnt = malloc(sizeof(point_t));
  pnt->x = x;
  pnt->y = y;
  pnt->flag = UNCONNECTED;
  pnt->next = NULL;
  if (path->start == NULL) path->start = path->end = pnt;
  else {
    path->end->next = pnt;
    path->end = pnt;
  }
}

void lineTo(path_t *path, float x, float y)
{
  point_t *pnt = malloc(sizeof(point_t));
  pnt->x = x;
  pnt->y = y;
  pnt->flag = CONNECTED;
  pnt->next = NULL;
  if (path->start == NULL) path->start = path->end = pnt;
  else {
    path->end->next = pnt;
    path->end = pnt;
  }
}

void stroke(path_t *path)
{
  point_t *p = path->start;

  while (p != NULL) {
    if (p->next && p->next->flag == CONNECTED)
      xline(p->x, p->y, p->next->x, p->next->y, plot);
    p = p->next;
  }
  if (path->flag == CONNECTED) {
    xline(path->start->x, path->start->y, path->end->x, path->end->y, plot);
  }
}
