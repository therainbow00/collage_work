#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 513;
    char *p = &x;
    for (int i = 0; i < sizeof(int); i++)
    {
        printf("%x\n", *p);
        p++;
    }
    return 0;
}
