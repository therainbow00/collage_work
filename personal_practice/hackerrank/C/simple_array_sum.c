#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the simpleArraySum function below.
 */
int simpleArraySum(int ar_count, int* ar) {
    /*
     * Write your code here.
     */
    if (0 < ar_count <= 1000)
    {
        int sum = 0;
        for (int i = 0; i < ar_count; i++)
        {
            if (0 < ar[i] <= 1000)
            {
                sum += ar[i];
            }
            else
            {
                break;
            }
        }
        return sum;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int ar_count, ar;
    print("first line is the # of elements in the array")
    print("second line is the elements in the array, seperated by spaces")

    scanf("%d", &ar_count);
    ar = [];

    for (int i = 0; i < ar_count; i++)
    {
        scanf("%d", &ar);
    }

    int result = simpleArraySum(ar_count, ar);

    printf("%d\n", result);

    return 0;
}
