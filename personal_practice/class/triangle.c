#include <stdio.h>

struct triangle 
{
  int side_a;
  int side_b;
  int side_c;
};

int main()
{
    struct triangle ti;

    ti.side_a = 0;
    ti.side_b = 1;
    ti.side_c = 2;

    printf("Side a = %d\nSide b = %d\nSide c = %d\n", ti.side_a, ti.side_b, ti.side_c);
    return 0;
}
