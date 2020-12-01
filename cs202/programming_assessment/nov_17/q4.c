/*Binary search tree.  Write a function named totalSum that takes as parameter the root of a binary search tree (with the following type) and returns the total sum of the numbers in the tree.  Note - making the function have the proper prototype is part of getting the answer correct.



struct tree {
  int data;
  struct tree *left, *right;
};
*/
int bst_totalSum(struct tree * root) {
  // base case: root == NULL
  if (root == NULL)
  {
      return 0;
  }

  int total = 0;

  // left
  //printf("root: %d (%d)\n", root, root->data);
  total += bst_totalSum(root->left);
  //printf("total (%d) += bst_totalSum(root->left (%d))\n", total, root->left);

  // right
  //printf("root: %d (%d)\n", root, root->data);
  total += bst_totalSum(root->right);
  //printf("total (%d) += bst_totalSum(root->right (%d))\n", total, root->right);

  // self
  total += root->data;
  //printf("total (%d) += root->data (%d)\n", total, root->data);

  return total;
}
