#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char num[1001], n[101] = "0123456789";
    int count = 0, i, length, length_n;
    scanf("%1000s", num);
    length_n = strlen(n);
    length = strlen(num);

    if (length >= 1 && length <= 1000)
    {
        for (int j = 0; j < length_n; j++)
        {
            for (i = 0; i < length; i++)
            {
                if (num[i] >= '0' && num[i] <= '9')
                {
                    if (num[i] == n[j])
                    {
                        count++;
                    }
                    else
                    {
                        count = 0;
                    }
                }
                printf("%d", count);
            }
            //printf("%c ", n[j]);
            //printf("%d ", count);
            count = 0;
            printf("\n");
        }
    }
    return 0;
}
