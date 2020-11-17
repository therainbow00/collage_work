/*
Binary search tree.  Write a function named countDown that takes as parameter the root of a binary search tree (with the following type) and prints the numbers in the tree from largest to smallest.  Note - making the function have the proper prototype is part of getting the answer correct.



struct tree {
  int data;
  struct tree *left, *right;
};
*/

int bst_print(struct tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // left
    int height_left = bst_print(root->left);

    // self
    printf("%*s%d\n", 3, "", root->data);

    // right
    int height_right = bst_print(root->right);

    if (height_left > height_right)
    {
        return height_left + 1;
    }
    else
    {
        return height_right + 1;
    }
}
