#include <stdio.h>
#include <string.h>

int main()
{
    char last[100], first[100], name[200];

    printf("Last: ");
    scanf("%99s", last);
    printf("First: ");
    scanf("%99s", first);

    name[0] = '\0';
    strcat(name, first);
    strcat(name, last);

    printf("Hi %s\n", name);
    sprintf(name, "%s %s", first, last);

    return 0;
}
