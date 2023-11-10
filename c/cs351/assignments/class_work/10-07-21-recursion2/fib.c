#include <stdio.h>
#include <stdlib.h>

unsigned long fib(int n)
{
  if (n < 2) return 1;
  return fib(n-1) + fib(n-2);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: fib <number>\n");
    return 0;
  }

  int n = atoi(argv[1]);
  printf("%lu\n", fib(n));

  return 0;
}
