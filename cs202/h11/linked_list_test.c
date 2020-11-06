/*
  h11 - complete the linked list functions that are labeled h11
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

// printf a linked list
void linked_list_print(struct node *head) {
  // loop through the linked list
  for(struct node *p = head; p != NULL; p = p->next) {
    printf("%d\n", p->data);
    /*printf("--------------------------\n"
	   "my address: %p\n"
	   "data:       %d\n"
	   "prev:       %p\n"
	   "next:       %p\n",
	   p, p->data, p->prev, p->next);*/
  }
}


// make a new node, set the data, update pointers so new node
//  is before head, return new node (to become the new head)
struct node *linked_list_insert(struct node *head, int data_to_insert) {
  struct node *p = new_node();
  p->data = data_to_insert;

  // p will be the new node.  this should become at the head of the list.
  head->prev = p;
  p->next = head;

  return p;
}


// if data_to_lookup is in the list, return a pointer to its node
//  otherwise return NULL
struct node *linked_list_lookup(struct node *head, int data_to_lookup) {
  // loop through the linked list
  for(struct node *p = head; p != NULL; p = p->next) {
    // check if p->data == data_to_lookup
    if (p->data == data_to_lookup) return p;
  }

  return NULL;
}

// return a count of the number of nodes
int linked_list_num_nodes(struct node *head) {
  int count = 0;

  // loop through the linked list
  for(struct node *p = head; p != NULL; p = p->next) {
    count ++;
  }
  return count;
}


// how many nodes have data > x
int linked_list_count_greater_than(struct node *head, int x) {
  int count = 0;

  // loop through the linked list
  for(struct node *p = head; p != NULL; p = p->next) {
    if (p->data > x)
      count ++;
  }
  return count;
}


// h11
// return the total sum of all nodes' data
// if head is NULL, return 0
int linked_list_sum(struct node *head) {
  struct node * h = head;
  if (h->data == NULL)
  {
      return 0;
  }
  int total = 0;
  total += linked_list_sum(h->next);
  return total;
}


// h11
// return the max from the list
// if head is NULL, return 0
int linked_list_max(struct node *head) {
  struct node * h = head;
  if (h == NULL)
  {
      return 0;
  }
  int max = 0;
  if (h->data < max)
  {
      max = linked_list_max(h->next);
  }
  return max;
}


// h11
// return a pointer to the tail of the list
// hint: loop until p->next == NULL
// if head == NULL, return NULL
struct node *linked_list_tail(struct node *head) {
  struct node * p = head;
  if (p == NULL)
  {
      return NULL;
  }
  for (struct node *p = head; p != NULL; p = p->next)
  {
      if (p->next == NULL)
      {
          return p;
      }
  }
}


// h11
// reverse the list, returning a pointer to the new head
// hint: loop through and swap next and prev for each node,
//   and return the last node as the new tail
struct node *linked_list_reverse(struct node *head) {
  struct node *p = head;

  return NULL;
}


// h11
// return the number of nodes that are smaller than the previous node
// if head is NULL, return 0
int linked_list_outOfOrder(struct node *head) {

  return 0;
}


// h11
// delete p_to_delete from the list
// return a pointer to the head of the list,
//  which will be head in general but will be head->next if head is the one being deleted
// remember to free the memory after adjusting pointer, etc.
struct node * linked_list_delete(struct node *head, struct node *p_to_delete) {
  // cases to deal with...

  // head or p_to_delete is NULL
  if (head == NULL)
  {
      return NULL;
  }
  else if (p_to_delete == NULL)
  {
      return head;
  }

  // head == p_to_delete

  // p_to_delete is not head (so p_to_delete->prev is not NULL, but p_to_delete->next could be)

  return head;
}


void run_tests(struct node *head, char *testWhat, int howMany);


int main(int argc, char *argv[]) {
  if (argc < 5) {
    printf("Usage: ./linked_list_test.o seed howMany testWhat printAll\n"
	   "  testWhat should be one of: sum, max, tail, reverse, outOfOrder, delete\n"
	   "printAll should be 0 or 1\n");
    exit(0);
  }
  int seed = atoi(argv[1]);
  int howMany = atoi(argv[2]);
  char *testWhat = argv[3];
  int printAll = atoi(argv[4]) != 0;

  srand(seed);

  struct node * head = NULL;

  // put random things into the linked list
  for(int i = 0; i < howMany; i++) {
    if (head == NULL) {
      head = new_node();
      head->data = rand() % 1000;
    }
    else
      head = linked_list_insert(head, rand() % 1000);
  }
  if (printAll) {
    printf("List before doing the tests...\n");
    linked_list_print(head);
    printf("And the test/result...\n");
  }

  // run the tests
  run_tests(head, testWhat, howMany);

  return 0;
}



// run the tests
//
void run_tests(struct node *head, char *testWhat, int howMany) {

  // call one of the functions depending on what the last command-line argument is
  if (strcmp(testWhat, "sum") == 0) {
    printf("%d\n", linked_list_sum(head));
  }
  else if (strcmp(testWhat, "max") == 0) {
    printf("%d\n", linked_list_max(head));
  }
  else if (strcmp(testWhat, "tail") == 0) {
    struct node * tail = linked_list_tail(head);
    if (tail != NULL)
      printf("%d\n", tail->data);
  }
  else if (strcmp(testWhat, "reverse") == 0) {
    printf("before...\n");
    linked_list_print(head);
    head = linked_list_reverse(head);
    printf("after...\n");
    linked_list_print(head);
  }
  else if (strcmp(testWhat, "outOfOrder") == 0) {
    int count = linked_list_outOfOrder(head);
    printf("%lf\n", (double)100 * count / howMany);
  }
  else if (strcmp(testWhat, "delete") == 0) {
    printf("before...\n");
    linked_list_print(head);
    for(int i=0; i < 100; i++) {
      struct node *p = linked_list_lookup(head, i);
      if (p != NULL) {
	printf("  delete %d\n", i);
	head = linked_list_delete(head, p);
      }
    }
    printf("after...\n");
    linked_list_print(head);
  }
  else {
    printf("Invalid testWhat.\n");
  }

}
