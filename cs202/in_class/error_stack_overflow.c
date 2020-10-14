#include <stdio.h>
#include <stdlib.h>

int how_many_g = 1000000;
int globel_arry[how_many_g]; // how_many * 4

int main()
{
    int how_many = 1000000;
    int arry[how_many]; // how_many * 4

    for (int i = 0; i < how_many; i++)
    {
        arry[i] = i;
    }

    int array_h[] = (int) malloc(sizeof(int) * how_many_g);

    for (int i = 0; i < how_many_g; i++)
    {
        globel_arry[i] = i;
        array_h[i] = i;
    }

    return 0;
}
