#include <stdio.h>

int main()
{
    // just char is asigned character. not 0 - 255, -128 to 127
    char x = 5; // 8 bits
               // 1111 1111b = 255
    x *= 10;

    x = 127; x = x + 1;
    printf("%d\n", x - 1);

    char y = 32; // z = 10 in hex that is a. %2x would print " a", %02 would print "0a"
    printf("0x%02x\n", y);

    y = -65
    printf("", );
    return 0;
}
