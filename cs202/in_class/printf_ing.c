#include <stdio.h>

#define FALSE 0

// key takeaway - everything is bits, everything is an interger
//              - interperct it in different ways

int main(int argc, char *argv[])
{
    int x = 100;

    printf("%d\n", x); // d for decimal
    printf("0x%x\n", x); // x for hexadcimal
    printf("%c\n", x + 1); // c for character
    printf("%o\n", x); // o for octal
    printf("%f\n", x) // f for float

    // floating point number, how is stored
    // scientific notation but bits
    // 6.02 x 10**23

    // note: 1 byte = 8 bits
    // char is bits, or 1 byte

    printf("sizeof char, int = %d, %d\n", sizof(char), sizof(int));
    return 0;
}
