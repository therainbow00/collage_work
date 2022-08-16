#include <stdio.h>

struct foo {
  int a, b, c;
};

struct foo bar = {.a = 1, .c = 5};

int main(void)
{
  printf("%x, bar.c = %d\n", &bar, bar.c);
  return 0;
}
