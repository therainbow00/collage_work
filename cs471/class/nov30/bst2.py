#!/usr/bin/env python3

import sys

def makenode(data):

    return {'data':data, 'count':1, 'left':None, 'right':None}

def insert(tree, data):

    while True:
        if data == tree['data']:
            tree['count'] += 1
            return
        if data < tree['data']:
            if tree['left'] != None:
                tree = tree['left']
            else:
                tree['left'] = makenode(data)
                return
        else:
            if tree['right'] != None:
                tree = tree['right']
            else:
                tree['right'] = makenode(data)
                return

def traverse(tree):

    if tree['left'] != None:
        traverse(tree['left'])
    print(tree['data'])
    if tree['right'] != None:
        traverse(tree['right'])

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

