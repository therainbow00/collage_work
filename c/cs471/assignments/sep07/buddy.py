#!/usr/bin/env python3

import sys
import numpy as np
from matplotlib import pyplot as plt

EMPTY = -1
INFTY = 0xdefaced

# 10010010
# 10000000

def nextpower2(x):
    global minsize

    i = 0
    while x:
        i += 1
        oldx = x
        x &= x-1
    return max(minsize, oldx if i == 1 else 2*oldx)

def findblockbysize(size):
    global blocks

    idx = None
    best = INFTY
    for i,b in enumerate(blocks):
        if b['pid'] == EMPTY and size <= b['size'] < best:
            idx, best = i, b['size']
    return idx

def splitblock(idx):
    global blocks

    blocks[idx]['size'] //= 2            # block to be split, cut in half
    newblock = blocks[idx].copy()        # create the new block for second half
    newblock['addr'] ^= newblock['size'] # make the address the buddy address
    blocks.insert(idx+1, newblock)       # inserts the newblock after its buddy
    return idx+1

def print_table():
    global blocks

    for b in blocks:
        print(f"{b['pid']:3d} {b['addr']:8b} {b['addr']:3d} {b['size']:8b} {b['size']:3d}")

def main():
    global blocks,minsize

    totalsize = int(sys.argv[1])
    minsize   = int(sys.argv[2])

    blocks = [ {'pid': EMPTY, 'addr': 0, 'size': totalsize} ]

    while True:
        s = input("? ")
        if s[0] == 'A':                              # doing an ADD
            pid, reqsize = map(int, s[2:].split())   # parse input
            size = nextpower2(reqsize)               # next power of 2
            idx = findblockbysize(size)              # find a free block of min feasible size
            while size < blocks[idx]['size']:        # split the block (maybe)
                idx = splitblock(idx)
            blocks[idx]['pid'] = pid                 # assign block to pid

        print_table()

if __name__ == "__main__":

    main()


