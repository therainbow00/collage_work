#!/usr/bin/env python3

import sys
import struct

from names import *

arg1 = sys.argv[1]

def readblock(fd, n):   # parameter descriptor and blocknumber
    fd.seek(1024 * n)     # assuming 1024 is the block size
    return fd.read(1024)

def main():

    with open(arg1,"rb") as fd:
        print('Superblock')
        sb = readblock(fd, 1)
        data = struct.unpack('<13I6H4I2HIHH', sb[:92])
        for i , x in enumerate(data):
            print(f'{x:10d} {sbfields[i]:s}')

        print('Block Group Descriptor Table')
        bgdt = readblock(fd , 2)
        data = struct.unpack('<3I3H', bgdt[:18])
        for i , x in enumerate(data):
            print(f'{x:10d} {bgdtfields[i]:s}')

if __name__ == "__main__":

    main()
