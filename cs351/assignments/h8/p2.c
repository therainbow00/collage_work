#include <stdio.h>
#include <stdlib.h>

struct point {
  int x, y;
};

/** (3pts)
 * Complete this function that reads an input file, composed of two integers
 * per line.  Use fscanf() in a loop to read the input, stop when it fails to
 * read 2 integers.  The function should return an array of 'struct point'
 * each array element containing the two values read.  The array of structures
 * should be dynamically allocated in units of 10 elements.  Set the npoints
 * value to the number of read integer pairs.
 */
struct point *get_data(FILE *fp, int *npoints)
{
    int space = 10, i = 0, x, y;
    struct point *value = malloc(space * sizeof(struct point));
    while ((fscanf(fp, "%d %d", &x, &y)) != EOF)
    {
        if (*npoints >= space - 1) value = realloc(value, (i += space) * sizeof(struct point));
        struct point temp;
        temp.x = x;
        temp.y = y;
        value[*npoints] = temp;
        i++;
        (*npoints)++;
    }
    return value;
    free(value);
    fclose(fp);
}


/**
 * Do not modify this part of the program.
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: p2 <filename>\n");
    return 0;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  int npoints = 0;
  struct point *data = get_data(fp, &npoints);

  int xsum = 0, ysum = 0;
  for(int i=0; i < npoints; i++) {
    xsum += data[i].x;
    ysum += data[i].y;
  }
  printf("npoints = %d, xsum = %d, ysum = %d\n", npoints, xsum, ysum);

  return 0;
}
