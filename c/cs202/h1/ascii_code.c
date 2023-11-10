// problem 6, ascii code

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        printf("%c: %d\n", c, c);
    }
    return 0;
}
