#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        perror("(%s) file is empty\n", argv[1]);
        return 1;
    }
    else
    {
        
    }
    return 0;
}
