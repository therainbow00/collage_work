#!/usr/bin/env python3

import sys

NOTHING = -1

def split(memblock):  # pid, address, size
    memblock['size'] //= 2
    newsize = memblock['size']
    address = memblock['address'] + newsize
    newblock = {'pid': NOTHING, 'address': address, 'size': newsize}
    return newblock

if __name__ == "__main__":

    foundblock = {'pid': NOTHING, 'address': 32, 'size': 16}

    print(foundblock)
    newblock = split(foundblock)
    print(foundblock)
    print(newblock)

    # append the newblock to the list
    # put the pid in newblock

# after adding new blocks:
# 1. find the block based on pid
# 2. mark it free (remove the id)
# 3. find it's buddy and is it free?

