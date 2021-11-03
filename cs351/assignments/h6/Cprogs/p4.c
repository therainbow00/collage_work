#include <stdio.h>

int main(void)
{
  for(int r = 0; r < 10; r++) {
    for(int c = 0; c <= r; c++) {
      putchar('*');
    }
    putchar('\n');
  }
  return 0;
}