#!/usr/bin/env python3

import sys

args = sys.argv[1:]

if len(args) > 0: # if arg 1 provided
    f = open(args[0], "r")
    data1 = f.read()
    f.close()
else:
    data1 = input("Manually enter data 1: ")

if len(args) > 1: # if arg 2 if provided
    f = open(args[1], "r")
    data2 = f.read()
    f.close()
else:
    data2 = input("Manually enter data 2: ")

result = data1[0] + data2[0] # doesn't matter

if len(args) > 2: # if arg 3 is provided
    f = open(args[2], "w")
    f.write(result)
    f.close()
else:
    print(result)
