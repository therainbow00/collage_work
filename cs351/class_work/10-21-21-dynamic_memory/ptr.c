#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char **ptr = malloc(sizeof(char *) * 10);
  ptr[0] = "ABC";

  printf("**ptr = '%16lx'\n", **ptr);

  return 0;
}
