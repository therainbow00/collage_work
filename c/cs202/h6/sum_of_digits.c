#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, num, total = 0, digit, i;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    if (n >= 10000 && n <= 99999)
    {

        for (i = 0; i < 5; i++)
        {
            num = n / (int) pow(10, i);
            digit = num % 10;
            total = digit + total;
        }
        printf("%d\n", total);
    }
    return 0;
}
