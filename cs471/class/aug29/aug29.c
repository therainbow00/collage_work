#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        print("%d: %s\n", i, argv[i]);
    }
    /*
    unsigned int hex_num;
    int i;
    scanf("%x", &hex_num);

    for (i = 31; i >= 0; i--)
    {
        if ((hex_num & (1 << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    */
    return 0;
}
