#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    int count = 0;

    while ((c = fgetc(stdin)) != EOF)
    {
        if (count < 1)
        {
            printf("%c", c);
            count++;
        }
        else
        {
            printf("*");
            count = 0;
        }
    }
    return 0;
}
