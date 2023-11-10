// create an array of 5 integers with malloc and set the values to 1, 2, 3, 4, 5
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = (int *) malloc(5 * sizeof(array));

    if (array == NULL)
    {
        printf("Memory not allocated.\n");
    }
    else
    {
        printf("Memory allocated.\n");
    }

    for (int i = 0; i < 5; i++)
    {
        array[i] = i + 1;
    }

    for (int j = 0; j < 5; j++)
    {
        printf("%d ", array[j]);
    }
    printf("\n");
    free(array);
    array = NULL;
    return 0;
}
