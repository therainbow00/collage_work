/*
  Do frequency counts of words in files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct node {
  char word[31]; // compare based on this
  int count;
  struct node *left, *right, *parent;
};


// allocate memory for a new node and initialize
struct node * new_node() {
  // allocate memory on the heap for a new node
  struct node *p =   (struct node *) malloc(sizeof(struct node));

  // initialize to reasonable values
  p->left = p->right = p->parent = NULL;
  p->count = 0;
  p->word[0] = '\0';

  return p;
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
    printf("%*s%s (%d)\n", depth*3, "", root->word, root->count);

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
struct node *  bst_insert(struct node *root, char *word_to_insert) {
  if (root == NULL) {
    struct node *pn = new_node();
    pn->count = 1;
    // note this would just copy the pointer
    // pn->word = word_to_insert;
    //strcpy(pn->word, word_to_insert); // unsafe
    strncpy(pn->word, word_to_insert, 30); // safe!
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
    // compare p->word and word_to_insert
    int compared = strcmp(word_to_insert, p->word); // like doing word_to_insert - p->word
    if (compared == 0) {
      return p;
    }
    else if (compared < 0 ) {
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
  pn->count = 1;
  strncpy(pn->word, word_to_insert, 30);
  pn->parent = p;

  // p is not NULL, and whichever way the new thing should go is NULL
  int compared = strcmp(word_to_insert, p->word);
  if (compared < 0) {
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
struct node * bst_lookup(struct node *root, char *word_to_lookup) {

  // set p to be the root, have p go left or right depending on
  //  data_to_lookup...
  struct node * p = root;

  while (p != NULL) {
    int compared = strcmp(word_to_lookup, p->word);
    if (compared == 0)
      return p;
    else if (compared < 0)
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
  Should return the number of nodes in the tree.
 */
int bst_num_nodes(struct node *root) {
  // if root is NULL return 0

  // set total = 1, counting the current node

  // add number of nodes in root->left

  // add number of nodes in root->right

  // return total

  return 0; // remove this once you have your code complete
}

/*
 */
struct node * bst_smallest(struct node *root) {
  if (root == NULL) return NULL;
  // note that after here in the function root is not NULL

  // method 1, using recursion
  if (root->left == NULL) return root;
  else { // root->left != NULL
    return bst_smallest(root->left);
  }

  /*

  // method 2, using loop
  while (root->left != NULL) {
    root = root->left;
  }
  // if we are here, root->left == NULL
  return root;

  */
}

/*
 */
struct node * bst_largest(struct node *root) {
}

/*
 */
int bst_totalSum(struct node * root) {
  // base case: root == NULL
  if (root == NULL) return 0;

  int total = 0;

  // left
  total += bst_totalSum(root->left);

  // right
  total += bst_totalSum(root->right);

  // self
  total += root->count;

  return total;
}

/*
  return the number nodes
 */
int bst_numNodes(struct node * root) {
  // same as totalSum but +1 instead of +root->count
}

/*
 */
void bst_printBetween(struct node *root, char *s1, char *s2) {
}

/*
  How many nodes have a count less than or equal to some value
 */
int bst_numNodes_lessThan(struct node *root, int count_cutoff) {
  if (root == NULL)
  {
      return 0;
  }

  int total = 0;

  // left
  //if (root->left != NULL) total += bst_numNodes_lessThan(root->left, count_cutoff);
  total += bst_numNodes_lessThan(root->left, count_cutoff);

  // right
  //if (root->right != NULL) total += bst_numNodes_lessThan(root->right, count_cutoff);
  total += bst_numNodes_lessThan(root->right, count_cutoff);

  // self
  if (root->count <= count_cutoff)
  {
      total++;
  }

  return total;
}

/*
 */
void bst_reverseOrder(struct node *root) {
}

/*
 */
void bst_numLeft_numRight(struct node *root) {
}

/*
 */
void bst_totalHeight(struct node *root) {
}





int main(int argc, char *argv[]) {
  FILE * f = NULL;

  // we will read either from a file or stdin, depending on arguments
  if (argc > 1) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      printf("Error opening %s\n", argv[1]);
      exit(0);
    }
  }
  else
    f = stdin;

  // read a word from f until EOF
  /* Each word
   * read in the word
   * check if we already have it (lookup operation)
   * if yes, increase count
   * if no, insert and set count = 1 (insert operation)
   */
  struct node * root = NULL;

  char s[31];
  while (fscanf(f, "%30s", s) == 1) {
    // convert s to lower-case
    for(int i=0; s[i] != '\0'; i++)
      s[i] = tolower(s[i]);
    //printf("%s\n", s);
    // todo: fix the punctuation
    //int i = 0; while (s[i] != '\0' && ispunct(s[i])) i++;
    //char *ss = &s[i];
    //i = strlen(ss);
    //(while i >= 0 && ispunct(ss[i])) i--;
    //ss[i+1] = '\0';

    struct node *p = bst_lookup(root, s);
    if (p == NULL) {
      p = bst_insert(root, s);
      if (root == NULL) root = p;
    }
    else {
      p->count ++;
    }
  }

  //bst_print(root);

  struct node * p = bst_smallest(root);
  //printf("%s (%d)\n", p->word, p->count);
  //printf("%d\n", bst_totalSum(root));
  printf("%d\n", bst_numNodes_lessThan(root, 1));

  fclose(f);

  return 0;
}
