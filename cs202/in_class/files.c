#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;

    FILE *f = popen("primes 1 10 | wc", "r");
    if (f == NULL)
    {
        printf("Unable to open file.\n");
        exit(0);
    }
    char s[100];
    while (fgets(s, 100, f) != NULL)
    {
        printf("%s", s);
    }
    pclose(f);
    return 0;
}
