#include <stdio.h>
#include <unistd.h>

int foo(int a, int b)
{
  char buf[8];
  int c = a + 2;
  int d = b + 4;

  read(STDIN_FILENO, buf, 64);
  printf("%d+%d ['%s']\n", c, d, buf);
  return a+b;
}

int main(void)
{
  foo(1, 2);

  return 0;
}
