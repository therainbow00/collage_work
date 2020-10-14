#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char* words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int n = a; n >= 1 && n <= b; n++)
    {
        if (n >= 1 && n <= 9)
        {
            printf("%s\n", words[n - 1]);
        }
        else if (n > 9)
        {
            if (n % 2 == 0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
    }

    return 0;
}
