#include <stdio.h>
#include <stdlib.h>

int globel_var1;
int globel_var2[10];
int globel_var3;

void function()
{
    int local_var4;
    printf("&local_var4: %p\n", &local_var4);
}

int main()
{
    int globel_var1;
    int globel_var2[10];
    int globel_var3;

    printf("Memory address for different parts of the program...\n")
    printf("Local variables...\n"
           "&local_var1: %p\n"
           "&local_var2: %p\n"
           "&local_var3: %p\n", &local_var1, &local_var2, &local_var3);

    int *heap_var1 = (int *) malloc(sizeof(int));
    int *heap_var2 = (int *) malloc(10 * sizeof(int));
    int *heap_var3 = (int *) malloc(sizeof(int));

    printf("Dynamically allocated memory...\n"
           "heap_var1: %p\n"
           "heap_var2: %p\n"
           "heap_var3: %p\n\n\n", heap_var1, heap_var2, heap_var3);

    printf("String constant..\n"
    "\"hello\" as a pointer: ")

    return 0;
}
