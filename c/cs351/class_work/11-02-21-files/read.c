#include <stdio.h>
#include <stdlib.h>

#define K	1024

int main(void)
{
  FILE *fp = fopen("scoreboard.txt", "r");
  char username[K];
  int score;

  printf("Scoreboard:\n");
  while (fscanf(fp, "%s %d\n", username, &score) == 2) {
    printf("User: %s, score: %d\n", username, score);
  }

  fclose(fp);
  return 0;
}
