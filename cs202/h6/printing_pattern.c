#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else if (y > x)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    //# rows and # cols is 2 * n - 1
    int m = 2 * n - 1;
    if (n >= 1 && n <= 1000)
    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < m; col++)
            {
                // some formula based on
                printf("%d ", max(abs(n - row - 1) + 1, abs(n - col - 1) + 1));
            }
            printf("\n");
        }
    }
    return 0;
}
