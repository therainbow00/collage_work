#!/usr/bin/env python3
import sys

if len(sys.argv) <= 1:
    print('You must provide arguments to this program')
    exit(1)
if "--version" in sys.argv or "-v" in sys.argv:
    print("v0.0.1")
    exit(0)
if "--help" in sys.argv or "-h" in sys.argv:
    print("This program prints out command line arguments each on their own line."
          " Examples: ./<filename.py> <argument1> <argument2> <argument3>... so on."
          " To check the version of the program, type: ./<filename.py> (<--v> or <--version>)")
    exit(0)
for i in range(1, len(sys.argv)):
    print(sys.argv[i])
