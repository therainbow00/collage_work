#!/usr/bin/env python3

import sys

class BST:

    def __init__(self, data):

        self.data = data
        self.count = 1
        self.left = None
        self.right = None

    def insert(self, newdata):

        tree = self
        while True:
            if newdata == tree.data:
                tree.count += 1
                return
            if newdata < tree.data:
                if tree.left != None:
                    tree = tree.left
                else:
                    tree.left = BST(newdata)
                    return
            else:
                if tree.right != None:
                    tree = tree.right
                else:
                    tree.right = BST(newdata)
                    return

    def traverse(self):    # inorder traversal

        if self.left:
            self.left.traverse()
        print(self.data)
        if self.right:
            self.right.traverse()

if __name__ == "__main__":

    tree = None
    for line in sys.stdin:
        data = line.rstrip()
        if tree == None:
            tree = BST(data)
        else:
            tree.insert(data)

    tree.traverse()

