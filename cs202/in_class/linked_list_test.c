#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a node of data
struct node {
  int data;
  struct node *prev, *next;
};

// allocate memory for a new node and initialize
struct node * new_node() {
  // allocate memory on the heap for a new node
  struct node *p =   (struct node *) malloc(sizeof(struct node));

  // initialize to reasonable values
  p->data = 0;
  p->prev = p->next = NULL;

  return p;
}

// print a linked list
void linked_list_print(struct node *head) {
    for (struct node *p = head; p != NULL; p = p->next)
    {
        printf("----------------------\n"
               "my address: %p\n"
               "data:        %d\n"
               "prev:        %p\n"
               "next:        %p\n", p->data, p->prev, p->next);
    }
}

struct node *linked_list_insert(struct node *head, int data_to_insert) {
    struct node *p = new_node();
    p->data = data_to_insert;

    head->prev = p;
    p->next = head;

    return p;
}

struct node *linked_list_lookup(struct node *head, int data_to_lookup) {
    for (struct node *p = head; p != NULL; p = p->next)
    {
        if (p->data == data_to_lookup)
        {
            return p;
        }
    }
    return NULL;
}

void linked_list_delete(struct node *head, struct node *p_to_delete) {
}

int linked_list_count_greater_than(struct node *head, int x)
{
    int count = 0;
    for (struct node *p = head; p != NULL; p = p->next)
    {
        if (p->data > x)
        {
            count++;
        }
    }
    return count;
}

int linked_list_num_nodes(struct node *head)
{
    int count = 0;
    for (struct node *p = head; p != NULL; p = p->next)
    {
        count++;
    }
    return count;
}

int main(int argc, char *arvg[]) {

  //srand(clock());


  struct node * head = NULL;

  head = new_node();
  for (int i = 0; i < 10; i++)
  {
      head = linked_list_insert(head, rand() % 100);
  }

  linked_list_print(head);

  printf("%d nodes\n", linked_list_num_nodes(head));
  printf("%d > %d\n", linked_list_count_greater_than(head, 50), 50);

  return 0;
}
