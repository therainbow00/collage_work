// problem 17, powers of two

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int k = 1, result;
    char text[10] = "2**";

    while (k <= 12)
    {
        result = (int) pow(2, k);
        printf("%s%d = %d\n", text, k, result);
        k++;
    }
    return 0;
}
