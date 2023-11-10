#!/usr/bin/env python3

import sys

def print_binary(n, nbits = 16):
    mask = 1 << (nbits - 1)
    while mask != 0:
        if (n & mask) == 0:
            print(0, end='', sep='')
        else:
            print(1, end='', sep='')
        mask >>= 1

if __name__ == "__main__":
    print_binary(85, 12)
    print()
    print_binary(-1, 16)
    print()

# two's complement arithmetic
