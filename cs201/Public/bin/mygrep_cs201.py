#!/usr/bin/env python3
import sys

print("my", end="")
print("grep", end="")
print(" program:")


args = sys.argv[1:]

if len(args) < 1:
    print("Must include a pattern as the first argument.", file=sys.stderr)
    sys.exit(1)

pattern = args[0]
print(pattern)

for line in sys.stdin:

    if pattern in line:
        print(line, end="")
