#include <stdio.h>

int main(void)
{
  int i = 1, c = 0;
  
  while (i <= 99) {
    c++;
    if (c < 5) {
      printf("%d\t", i);
    } else {
      printf("%d\n", i);
      c = 0;
    }

    i += 2;
  }
  return 0;
}
