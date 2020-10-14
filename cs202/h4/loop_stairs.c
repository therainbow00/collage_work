
#include <stdio.h>

int main(int argc, char *argv[])
{
    int num, i, j, k, middle_value, space_value;
    scanf("%d", &num);
    middle_value = 0;
    if (num > 0)
    {
        for (i = 1; i < num + 1; i++)
        {
            space_value = num - i;
            printf("%.*s", space_value, "                                                  ");
            printf("/");

            printf("%.*s", middle_value, "                                                  ");
            printf("\\\n");

            middle_value += 2;
        }
    }
    return 0;
}
