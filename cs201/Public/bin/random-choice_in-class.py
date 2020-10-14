#!/usr/bin/env python3

import sys
import random

rawargs = sys.argv[1:]

stdins = []
for line in sys.stdin:
    line = line.strip()
    stdins.append(line)

selection_num = 1

allowDuplicates = False
if "-d" in rawargs or "--duplicates" in rawargs:
    allowDuplicates = True

for arg in rawargs:
    if len(arg) and arg[0] == "-":
        continue
    try:
        selection_num = int(arg)
        break
    except:
        print("You must supply an interger argument", file=sys.stderr)
        sys.exit(1)

#print("selection_num", selection_num)
#print("allowDuplicates", allowDuplicates)

selection = []

for i in range(selection_num):
    sel = random.choice(stdins)
    if not allowDuplicates:
        stdins.remove(sel)
    selection.append(sel)

for selections in selection:
    print(selections)
