#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
  int value;
  node_t *next;
};

// Allocates in memory (heap) a node structure and assigns value to it and sets
// it's next pointer to NULL and returns the address of it:
node_t *new_node(int value)
{
  node_t *n = malloc(sizeof(node_t));
  n->value = value;
  n->next = NULL;
  return n;
}

int main(void)
{
  int num;
  // "head" represents the start of a linked list, initialized to point to
  // nothing, i.e. nothing is in the list.
  node_t *t, *p, *head = NULL, *end = NULL;

  while (scanf("%d", &num) == 1) {
    // Allocate a new node, and place the num value in it:
    t = new_node(num);
//     // Insert the node immediately at the head of the list:
//     // Much like pushing an element onto a stack:
//     t->next = head;
//     head = t;

    // Adds an element to the end of the list.  The first part of the if only
    // happens once (the first time through the loop,) thereafter head not
    // updated, only end:
    if (end == NULL) head = end = t;
    else {
      end->next = t;
      end = t;
    }
  }

  for(p = t = head; t != NULL; p = t) {
    printf("%d\n", t->value);
    t=t->next;
    free(p);
  }

  return 0;
}
