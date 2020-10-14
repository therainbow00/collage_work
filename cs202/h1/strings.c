#include <stdio.h>
#include <string.h>

int strlen2(char s[])
{
    int k;
    for (k = 0; s[k] != '\0'; k++)
    ;
    // when loop is over, s[k] == '\0'
    return k;
}
//     012
// s: 'hi\0'

int strcmp2(char s1[], char s2[])
{
    int k;
    for (k = 0; s1[k] != '\0' && s2[k] != '\0'; k++)
    {
        if (s1[k] != s2[k])
        {
            return 1;
        }
    }
    // if (strlen(s1) == strlen(s2)) return 0;
    //else return 1;
    if (s1[k] == s2[k]) return 0;
    else return 0;
}
// k: 012345

int main()
{
    char s[100];

    s[0] = 'h';
    s[1] = 'i';
    s[2] = ' ';
    s[3] = 'c';
    s[4] = 'a';
    s[5] = 't';
    s[6] = '\0';

    printf("String: %s\n", s);

    printf("String: %d\n", s);
}
