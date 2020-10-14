#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data; // string or other data
    struct node *left, *right, *parent;
};

struct node * new_node()
{
    struct node *p = malloc(sizeof(struct node));

    p->data = 0;
    p->left = p->right = p->parent = NULL;

    return 0;
}
struct node * tree_demo()
{
    struct node *n1 = new_node(), *n2 = new_node(), *n3 = new_node(), *n4 = new_node();

    n1->data = 10;
    n1->left = n2;
    n1->right = n3;

    n2->data = 7;
    n2->parent = n1;

    n3->data = 12;
    n3->parent = n1;

    n4->parent = n2;
    n4->data = 3;
    n2->left = n4;

    return n1;
}

int bst_print(struct node *root, int depth)
{
    if (root == NULL)
    {
        return 0;
    }
    // left
    int height_left = bst_print(root->left, depth + 1);

    // self
    printf("%*s%d\n", depth * 3, "", root->data);

    // right
    int height_right = bst_print(root->right, depth + 1);

    if (height_left > height_right)
    {
        return height_left + 1;
    }
    else
    {
        return height_right + 1;
    }
}

struct node * bst_insert(struct node *root, int data_to_insert)
{
    // basic idea: do a lookup for data, when find NULL, that's where
    // to put it.
    if (root == NULL)
    {
        struct node *pn = new_node();
        pn->data = data_to_insert;
        return pn;
    }
    struct node * p = root;

    // note: can assume root is not NULL
    // noteL duplicates not allowed, if data_to_insert is already present just return pointer to it

    // loop through, let p go left or right, if
    while (p != NULL)
    {
        if (data_to_insert == p->data)
        {
            return p;
        }
        else if (data_to_insert < p->data)
        {
            if (p->left == NULL)
            {
                break;
            }
            else
            {
                p = p->left;
            }
        }
        else
        {
            if (p->right == NULL)
            {
                break;
            }
            else
            {
                p = p->right;
            }
        }
    }
    // p should now be pointing to the node that will be the parent
    // create the new node, set parent
    struct node *pn = new_node();
    pn->data = data_to_insert;
    pn->parent = p;

    if (data_to_insert < p->data)
    {
        p->left = pn;
    }
    else
    {
        p->right = pn;
    }
    return pn;
}

struct node * bst_lookup(struct node *root, int data_to_lookup)
{
    struct node * p = root;

    while (p != NULL)
    {
        if (data_to_lookup == p->data)
        {
            return 0;
        }
        else if (data_to_lookup < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
}

void bst_delete(struct node *root, struct node *p_to_delete)
{

}

int main()
{
    struct node * root = tree_demo();

    bst_print(root, 0);

    struct node *p = bst_lookup(root, 3);
    if (p == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Yes found\n");
    }
    printf("Inserting 20...\n");
    bst_insert(root, 20);

    printf("Inserting 11...\n");
    bst_insert(root, 11);

    bst_print(root, 0);

    int x = bst_print(root, 0);
    printf("Height of tree: %d\n");

    return 0;
}
