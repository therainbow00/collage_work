/*
  Order to review functions:
  new_node
  tree_demo
  bst_lookup
  bst_print
  bst_insert
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct node {
   int data;
   struct node *left, *right, *parent;
};

struct node * new_node() {
  // allocate memory on the heap for a new node
  struct node *p =   (struct node *) malloc(sizeof(struct node));

  // initialize to reasonable values
  p->data = 0;
  p->left = p->right = p->parent = NULL;

  return p;
}

struct node * tree_demo() {
  struct node *n1 = new_node(),
    *n2 = new_node(),
    *n3 = new_node(),
    *n4 = new_node();

/*
  n1->data = 10; // (*n1).data = 10;
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
*/
}

// bst_print
// print the tree
// return the depth as well
int bst_print(struct node *root, int depth) {
  if (root == NULL) return 0;

  // left
  int height_left =
    bst_print(root->left, depth+1);

  // self
  printf("%*s%d\n", depth*3, "", root->data);

  // right
  int height_right =
    bst_print(root->right, depth+1);

  if (height_left > height_right) return height_left+1;
  else return height_right+1;
}



// bst_insert
// create new node for given data, insert into tree, return pointer to the
//  new node in case the caller wants to do something with that.
// return NULL if there was a problem
//
// if root is NULL, create a node and return it
//
// note: duplicates not allowed, if data_to_insert is already presen
//  just return a pointer to its node.
struct node *  bst_insert(struct node *root, int data_to_insert) {
  if (root == NULL) {
    struct node *pn = new_node();
    pn->data = data_to_insert;
    return pn;
  }

  // note: can assume root is not NULL

  // basic idea: do a lookup for data, when find NULL, that's where
  //  to put it.

  struct node * p = root;

  // loop through, let p go left or right, if we find data_to_insert
  //  return it.  otherwise, stop p where it will be the parent
  //  of the new node
  while (p != NULL) {
    if (data_to_insert == p->data) {
      return p;
    }
    else if (data_to_insert < p->data) {
      if (p-> left == NULL)
	break;
      else
	p = p->left;
    }
    else {
      if (p->right == NULL)
	break;
      else
	p = p->right;
    }
  }

  // p should now be pointing to the node that will be the parent

  // creat the new node, set parent
  struct node *pn = new_node();
  pn->data = data_to_insert;
  pn->parent = p;

  // p is not NULL, and whichever way the new thing should go is NULL
  if (data_to_insert < p->data) {
    // put new thing at p->left
    p->left = pn;
  }
  else {
    // put new thing at p->right
    p->right = pn;
  }

  return pn;
}


// bst_lookup
// return pointer to node with the given data, or NULL if not found
struct node * bst_lookup(struct node *root, int data_to_lookup) {

  // set p to be the root, have p go left or right depending on
  //  data_to_lookup...
  struct node * p = root;

  while (p != NULL) {
    if (data_to_lookup == p->data)
      return p;
    else if (data_to_lookup < p->data)
      p = p->left;
    else
      p = p->right;
  }

  return NULL;
}


// bst_delete
void bst_delete(struct node *root, struct node *p_to_delete) {
}

int bst_totalSum(struct node * root) {
  // base case: root == NULL
  if (root == NULL)
  {
      return 0;
  }

  int total = 0;

  // left
  printf("\n---------------------------------\n");
  printf("left\n");
  printf("root: %p (%d)\n", root, root->data);
  total += bst_totalSum(root->left);
  printf("total (%d) += bst_totalSum(root->left (%p))\n", total, root->left);
  printf("---------------------------------\n");

  // right
  printf("\n---------------------------------\n");
  printf("right\n");
  printf("root: %p (%d)\n", root, root->data);
  total += bst_totalSum(root->right);
  printf("total (%d) += bst_totalSum(root->right (%p))\n", total, root->right);
  printf("---------------------------------\n");

  // self
  printf("\n---------------------------------\n");
  total += root->data;
  printf("total (%d) += root->data (%d)\n", total, root->data);
  printf("---------------------------------\n");

  return total;
}

int bst_total_sum(struct node * root)
{
    int total = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        total += root->data;
    }

    bst_total_sum(root->left);
    bst_total_sum(root->right);

    return total;
}

int main(int argc, char *argv[]) {

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

  printf("Inserting 1...\n");
  bst_insert(root, 1);

  printf("Inserting 2...\n");
  bst_insert(root, 2);

  printf("Inserting 5...\n");
  bst_insert(root, 5);

  printf("Inserting 7...\n");
  bst_insert(root, 7);

  printf("Inserting 3...\n");
  bst_insert(root, 3);

  bst_print(root, 0);

  int sum = bst_totalSum(root);
  printf("Total sum of tree: %d\n", sum);

  int sum_1 = bst_total_sum(root);
  printf("numbers added up in tree: %d\n", sum_1);

  /*  printf("Inserting random values...\n");
  for(int i=0; i < 30; i++) {
    int x = rand() % 100 - 50;
    bst_insert(root, x);
    }*/

  int x = bst_print(root, 0);
  printf("Height of tree: %d\n", x);

  return 0;
}
