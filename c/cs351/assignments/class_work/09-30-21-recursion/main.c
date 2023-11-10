#include <stdio.h>
#include <stdlib.h>

unsigned long fact(int num);

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: fact <number>\n");
    return 1;
  }

  int num = atoi(argv[1]);

  printf("%lu\n", fact(num));

  return 0;
}
