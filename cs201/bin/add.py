#!/usr/bin/env python3

import sys

sum = 0

for line in sys.stdin:
    line = line.strip()
    sum += int(line)

print(sum)
