/*
Linked list.  Complete the function that takes as parameter the head of a linked list and prints the linked list in reverse order.  If the linked had the contents



of, the, and, on, a, an, ok



then the correct printout would be



ok, an, a, on, and, the, of



struct node {
  char word[31];
  struct node *prev, next;
};
*/


void print_reverse(struct node *head) {
    struct node *h = head;
    struct node *n = NULL;
    struct node *p = NULL;
    struct node *c = head;
    if (h == NULL)
    {
        return 0;
    }

    n = h->next;

    while (n != NULL)
    {
        c = n;
        c->next = p;
        n = n->next;
        p = c->prev;
    }
    h = c;
    for (struct node *h = head; h != NULL; h = h->next)
    {
        printf("%s, ", h->word);
    }
}
