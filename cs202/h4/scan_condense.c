#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int i, j = 0, length, c;
    while ((c = fgetc(stdin)) != EOF)
    {
        if (isalpha(c))
        {
            printf("%c", c);
        }
    }
    return 0;
}
