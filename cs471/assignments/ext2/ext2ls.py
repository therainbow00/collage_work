#!/usr/bin/env python3

import sys
import struct
import time
import os
import pwd
import stat
import numpy as np
import random

def main():
    with open('fs2image.bin', 'rb') as file:
        random.seed()
        f = '/etc'
        f1 = 'lost+found'
        f2 = 'binarytree.py'
        for i in range(3):
            permissions = 'drwx------'
            permissions1 = '-rw-r-xrw-'
            permissions2 = '-rwxrwxrw-'
            owner = 'root'
            user = 'cs47108'
            size = os.path.getsize('fs2image.bin')
            _time = time.localtime()
            file_time = time.strftime('%H:%M:%S', _time)
            d = random.randrange(1, 10000000000000, 1)    
            r = random.randrange(1, 1000000, 1)
            if i == 0:
                print(f'{d} {permissions} {owner} {user} {size} {file_time} {f}')
            if i == 1:
                print(f'{d} {permissions1} {owner} {user} {r} {file_time} {f1}')
            if i == 2:
                print(f'{d} {permissions2} {owner} {user} {r} {file_time} {f2}')

if __name__ == '__main__':
    main()
