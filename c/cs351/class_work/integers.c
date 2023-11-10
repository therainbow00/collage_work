#include <stdio.h>

int main(void)
{
    /*
     * "int" defines a 32 bit signed integer by default:
     * +- ~ 2billion
     * An "unsigned int" defines a 32 bit unsigned integer:
     * 0 - ~ 4 billion
    */
    int a = 5, b = 95;
    int c;

    c = a + b;

    /*
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    */

    printf("a = %3d\nb = %3d\nc = %3d\n", a, b, c);

    return 0;
}
