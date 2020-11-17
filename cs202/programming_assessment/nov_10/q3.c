/*
Linked list.  Complete the function that takes as parameter the head of a linked list and prints any numbers that are out of order (smaller than the previous).  If the linked had the contents 1, 2, 7, 6, 5, 8, 3, 4, then the function would print

6
5
3



struct node {
  int number;
  struct node *link;
};



void out_of_order(struct node *head)
*/
{
    struct node * p = head;
    if (p == NULL)
    {
        return 0;
    }
    for (struct node * p = head; p != NULL; p = p->link)
    {
        if (p->link != NULL)
        {
            if (p->number > p->link->number)
            {
                printf("%d\n", p->link->number);
            }
        }
    }
}
