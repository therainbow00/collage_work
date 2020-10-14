#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 3;
    scanf("%d", &n);

    //int nums[n];
    int * nums[] = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        nums[i] = 0;
    }

    for(int i = 0; i < 3; i++)
    {
        scanf("%d", %nums[i]);
    }

    for(int i = n; i >= 0; i--)
    {
        printf("%d\n", nums[i]);
    }

    free(nums);
    nums = NULL;

    return 0;
}
