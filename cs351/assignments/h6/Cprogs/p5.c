#include <stdio.h>

int rows = 11;
int spaces = 10;
int stars = 1;

int main(void)
{
  while (rows > 0) {
    for(int i=0; i < spaces; i++) putchar(' ');
    for(int i=0; i < stars; i++) putchar('*');
    putchar('\n');
    spaces--;
    stars += 2;
    rows--;
  }
  return 0;
}