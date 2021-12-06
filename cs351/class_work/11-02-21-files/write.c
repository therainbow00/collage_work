#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

#define SCOREBOARD	"scoreboard.txt"

int R(int a, int b)
{
  int d = abs(b-a)+1;		// "distance" between a and b
  int m = a < b? a: b;		// minimum of a and b
  return m + (rand() % d);	// random value between a and b (inclusive)
}

int main(void)
{
  FILE *fp = fopen(SCOREBOARD, "a");

  chmod(SCOREBOARD, 0666);
  srand(time(0));

  fprintf(fp, "%s %d\n", getenv("USER"), R(1000, 10000));
  fclose(fp);

  return 0;
}
