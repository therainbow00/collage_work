#include <stdio.h>
#include <stdlib.h>

int countbits(int x)
{
    int i;
    for (i = 0; x; i++)
    {
        x &= x - 1;
    }
    return i;
}

void printbinary(int x)
{
    unsigned int mask = 1 << 31;
    while (mask)
    {
        putchar((mask & x) ? '1' : '0');
        mask >>= 1;
    }
    putchar('\n');    
}

int main(int argc, char *argv[])
{
    //print_to_binary(atoi(argv[1]));
    int x;
    
    x = atoi(argv[1]);
    printbinary(x);
    printf("%d\n", countbits(x));
    return 0;
}
