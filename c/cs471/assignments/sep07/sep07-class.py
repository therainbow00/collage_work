#!/usr/bin/env python3

EMPTY = -1
INFTY = 0xdefaced
import sys
import numpy as np
from matplotlib import pyplot as plt

def nextpower2(x):
    global minsize

    i = 0
    while x:
        i += 1
        oldx = x
        x &= x - 1
    return max(minsize, oldx if i == 1 else 2 * oldx)

def findblockbysize(size):
    global blocks

    idx = None
    best = INFTY
    for i, b in enumerate(blocks):
        if b['pid'] == EMPTY and size <= b['size'] < best:
            idx, best = i, b['size']
    return idx

def splitblock(idx):
    global blocks

    blocks[idx]['size'] //= 2
    newblock = blocks[idx].copy()
    newbock['address'] ^= newblock['size']
    blocks.insert(idex + 1, newbock)
    return idx + 1

def print_table():
    global blocks

    for b in blocks:
        print(f'{b['pid']: 3d} {b['address']: 8b} {b['address']: 3d} {b['size']: 8b} {b['size']: 3d}')

def main():
    totalsize = int(sys.argv[1])
    global minsize
    minsize = int(sys.argv[2])

    global blocks
    blocks = [{'pid': EMPTY, 'address': 0, 'size': totalsize}]

    while True:
        s = input('? ')
        if s[0] == 'A':
            pid, reqsize = map(int, s[2:].split())
            size = nextpower2(reqsize)
            idx = findblockbysize(size)
            while size < blocks[idx]['size']:
                idx = splitblock(idx)
            blocks[idx]['pid'] = pid

        print_table()
if __name__ == '__main__':
    main()
