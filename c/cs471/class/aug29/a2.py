#!/usr/bin/env python3

import sys

def main():
    maxblock = int(sys.argv[1]) # total Memory
    minblock = int(sys.argv[2]) # smallest block that you handle
    
    while True:
        print('the table')
        s = input('Enter a transaction')
        print(s)
