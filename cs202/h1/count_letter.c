#include <stdio.h>

int main(int argc, char *argv[])
{
    char s[101];
    char c;
    int i;
    int count = 0;

    printf("Enter the string: ");
    gets(s);
    printf("Enter character to be searched: ");
    scanf("%c", &c);

    for (i = 0; s[i]; i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }

    printf("characters '%c' occurs %d times \n", c, count);
    return 0;
}
