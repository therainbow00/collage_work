#include <stdio.h>
#include <stdlib.h>

struct point {
  int x, y;
  struct point *next;
};

/** (3pts)
 * Complete this function that reads the same input as h2, but in the form
 * of a linked list.  A struct point structure should be allocated for each
 * pair of integers read.  The next pointer should point to the next (or
 * previous, depending on how you wish to implement it,) point structure.
 * The point structures do not need to be arranged in the same order as they
 * are read in as, which should make implementation easier.  The returned
 * value should be that head of the accumulated linked list of data points.
 */
struct point *get_data(FILE *fp)
{
    int x, y;
    struct point *head = NULL;
    while ((fscanf(fp, "%d %d", &x, &y)) != EOF)
    {
        struct point *value = (struct point *) malloc(sizeof(struct point));
        value->x = x;
        value->y = y;
        value->next = head;
        head = value;
    }
    return head;
}

/**
 * Do not modify this part of the program.
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: p3 <filename>\n");
    return 0;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  int npoints = 0;
  struct point *data = get_data(fp);

  int xsum = 0, ysum = 0;
  while (data != NULL) {
    xsum += data->x;
    ysum += data->y;
    data = data->next;
  }
  printf("xsum = %d, ysum = %d\n", xsum, ysum);

  return 0;
}
