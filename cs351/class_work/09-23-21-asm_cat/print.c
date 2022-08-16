#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 3) {
    printf("Usage: print <name> <number>\n");
    return 0;
  }

  int num = atoi(argv[2]);

  printf("Name: %s (%d)\n", argv[1], num);

  return 0;
}
