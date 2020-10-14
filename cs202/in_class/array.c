#include <stdio.h>
#include <stdlib.h>

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
    A->num_nodes;
    A->num_nodes++;
}

struct node *array_lookup(struct array *A, int data_to_insert)
{

}

int main()
{
    struct array *arr = array_demo();

    array_print(arr);

    array_insert(arr, )
}
