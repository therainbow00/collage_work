#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int *arr, n, num = 0;
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    if (n >= 1 && n <= 1000)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);

            if (arr[i] >= 1 && arr[i] <= 1000)
            {
                num = num + arr[i];
            }
        }
        printf("%d\n", num);

    }
    free(arr);
    arr = NULL;

    return 0;
}
