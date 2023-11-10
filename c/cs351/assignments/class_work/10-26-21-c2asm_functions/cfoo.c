#include <stdio.h>

//int foo(int a, int b, char *str);

int foo(int a, int b, char *str)
{
  printf("%s -> %d\n", str, a+b);
  return a+b;
}

// int main(void)
// {
//   printf("foo = %d\n", foo(1, 5, "Hello, world!"));
//
//   return 0;
// }
