#!/usr/bin/env python3

import sys

DATA = 0
COUNT = 1
LEFT = 2
RIGHT = 3

def makenode(data):

    return [data, 1, None, None]

def insert(tree, data):

    while True:
        if data == tree[DATA]:
            tree[COUNT] += 1
            return
        if data < tree[DATA]:
            if tree[LEFT] != None:
                tree = tree[LEFT]
            else:
                tree[LEFT] = makenode(data)
                return
        else:
            if tree[RIGHT] != None:
                tree = tree[RIGHT]
            else:
                tree[RIGHT] = makenode(data)
                return

def traverse(tree):

    if tree[LEFT] != None:
        traverse(tree[LEFT])
    print(tree[DATA])
    if tree[RIGHT] != None:
        traverse(tree[RIGHT])

if __name__ == "__main__":

    tree = None
    for line in sys.stdin:
        data = line.rstrip()
        if tree == None:
            tree = makenode(data)
        else:
            insert(tree,data)

    traverse(tree)

    print(tree)

