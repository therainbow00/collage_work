#!/usr/bin/env python3

import sys
import random

arguments = sys.argv[1:]

if not len(arguments):
    print("You must provide a positive interger as the first argument for the number of random numbers to generate.")
    sys.exit(1)
number = int(arguments[0])

list = list(range(1, number + 1))
random.shuffle(list)
list = map(lambda number: str(number), list)
print(" ".join(list))
