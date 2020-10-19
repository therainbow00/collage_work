#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
};

struct array
{
    struct node *start;
    int num_nodes;
    int max_nodes;
};

struct array * new_array()
{
    struct array * arr = (struct array *) malloc(sizeof(struct array));

    arr->num_nodes = 0;
    arr->max_nodes = 100;

    arr->start = (struct node *) malloc(arr->max_nodes * sizeof(struct node));

    return arr;
}

struct array *array_demo()
{
    struct array * A = new_array();

    A->start[0].data = 10;
    A->start[1].data = 7;
    A->start[2].data = 12;
    A->start[3].data = 3;
    A->num_nodes = 4;

    return A;
}

void array_print(struct array *A)
{
    for (int i = 0; i < A->num_nodes; i++)
    {
        printf("%d\n", A->start[i].data);
    }
}

struct node *array_insert(struct array *A, int data_to_insert)
{
    if (A->num_nodes >= A->max_nodes)
    {
        A->max_nodes *= 2;
        A->start = realloc(A->start, sizeof(struct node) * A->max_nodes);
    }
    A->start[A->num_nodes].data = data_to_insert;
    A->num_nodes++;
    return &(A->start[A->num_nodes - 1]);
}

struct node *array_lookup(struct array *A, int data_to_lookup)
{
    for (int i = 0; i < A->num_nodes; i++)
    {
        if (A->start[i].data == data_to_lookup)
        {
            return &(A->start[i]);
        }
    }
    return NULL;
}

int main()
{
    //srand(clock());

    struct array * arr = new_array();

    /*
    each insert is constant, so total time is constant * N
    */
    int found = 0;
    for (int i = 0; i < 1000000; i++)
    {
        array_insert(arr, rand());
        struct node * p = array_lookup(arr, rand());
        if (p != NULL)
        {
            found++;
        }
    }
    //array_print(arr);
    printf("Found %d times\n", found);

    /*
    array_insert(arr, 13);
    array_insert(arr, 22);

    printf("After inserting some more...\n");

    array_printf(arr);
    */
    return 0;
}
