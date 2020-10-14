#!/usr/bin/env python3

import sys

arg = sys.argv[1:]

user = int(input("How far do yoy want to go? (type a #): "))

for arg in range(user + 1):
    print(arg)
