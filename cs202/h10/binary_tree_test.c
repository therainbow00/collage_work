/*
  h10 assignment: complete all of the items marked h10 in comments,
   and make your program behave exactly the same as Jeff's compiled
   version binary_tree_test_jeff.o

  A few to try out with Jeff's and yours
  ./binary_tree_test_jeff.o 10 100 1 1 # small test, print the tree
  ./binary_tree_test_jeff.o 1000000 10000000 -5 # larger test
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


struct node {
  int data;
  struct node *left, *right, *parent;
};

// allocate memory for a new node and initialize
struct node * new_node() {
  // allocate memory on the heap for a new node
  struct node *p =   (struct node *) malloc(sizeof(struct node));

  // initialize to reasonable values
  p->data = 0;
  p->left = p->right = p->parent = NULL;

  return p;
}

// creating a tree manually by creating nodes and setting parent/left/right
struct node * tree_demo() {
  struct node *n1 = new_node(),
    *n2 = new_node(),
    *n3 = new_node(),
    *n4 = new_node();

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
}

// helper function used by bst_print and bst_depth
// traverse the tree in-order (left, self, right) keeping track
//  of the depth and optionally printing if doPrint is set
int bst_print_helper(struct node *root, int depth, int doPrint) {
  if (root == NULL) return 0;

  // left
  int height_left =
    bst_print_helper(root->left, depth+1, doPrint);

  // self
  if (doPrint)
    printf("%*s%d\n", depth*3, "", root->data);

  // right
  int height_right =
    bst_print_helper(root->right, depth+1, doPrint);

  if (height_left > height_right) return height_left+1;
  else return height_right+1;
}

// print the tree
void bst_print(struct node *root) {
  bst_print_helper(root,
		   0,  // starting the helper function at depth 0
		   1); // yes print
}

int bst_depth(struct node *root) {
  return bst_print_helper(root,
			  0,  // starting the helper function at depth 0
			  0); // do not print
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

/*
  h10: Should return the number of nodes in the tree.
 */
int bst_num_nodes(struct node *root) {
  // if root is NULL return 0
  struct node * p = root;
  if (p == NULL)
  {
      return 0;
  }

  // set total = 1, counting the current node
  int total = 1;

  // add number of nodes in root->left
  if (p->left)
  {
      total++;
  }

  // add number of nodes in root->right
  if (p->right)
  {
      total++;
  }

  // return total
  return total; // change to total when code is complete
}

/*
  h10: Should free all the memory allocated in this tree.
 */
void bst_free(struct node *root) {
  // if root is NULL, return
  struct node * p = root;
  if (p == NULL)
  {
      return 0;
  }

  // call bst_free on root->left
  bst_free(p->left)

  // call bst_free on root->right
  bst_free(p->right)

  // call free on root
  free(p);
}


int main(int argc, char *argv[]) {
  // parameters that can be changes using command-line arguments
  // these are the defaults
  int how_many_to_insert = 1000000;
  int mod_by = how_many_to_insert * 10;
  int seed = 1;
  int print = 0;

  // letting user know what command-line arguments mean
  printf("Note, usage is: ./binary_tree_test.o [num_to_insert] [mod_by] [seed] [0|1 for print]\n");
  printf(" default values: %d, %d, %d, %d\n", how_many_to_insert, mod_by, seed, print);
  printf(" note: set seed=-x to run test for all seeds 1..x\n\n");

  /*
    Note - because of the way this code works, the only way to
    specify later arguments is to also specify earlier ones.  E.g.,
    the only way to set print=1 with command-line arguments is to
    also specify the ones before it.
   */
  if (argc > 1)
    how_many_to_insert = atoi(argv[1]);
  if (argc > 2)
    mod_by = atoi(argv[2]);
  if (argc > 3)
    seed = atoi(argv[3]);
  if (argc > 4)
    print = atoi(argv[4]);

  // set the range that we will set the random seed for multiple
  //  tests
  int start, end;
  if (seed < 0) { start = 1; end = -seed;}
  else {start = seed; end = seed;}

  // seed for random numbers
  srand(start);

  // start with empty tree
  struct node * root = NULL;

  // h10: print out the parameters we are using
  for(int i=0; i < how_many_to_insert; i++) {
    // pick a random value to insert into the tree
    int val = rand() % mod_by;

    // h10: if print is set, print val
    if (print)
    {
        printf("%d\n", val);
    }

    if (root == NULL) {
      root = new_node();
      root->data = val;
    }
    else
      bst_insert(root, val);
  }
  // h10: if print is set, print the tree
  if (print)
  {
      bst_print(val);
  }

  int depth = bst_depth(root);
  int num_nodes = bst_num_nodes(root);
  int best = floor(log2(num_nodes))+1; // best possible depth

  // h10: print off the results

  // free the memory from the tree
  bst_free(root);

  // h10: after getting all of that working, put it all into a
  //  for loop where you set the seed from start up through end.


  return 0;
}
