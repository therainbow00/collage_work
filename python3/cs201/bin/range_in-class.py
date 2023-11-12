#!/usr/bin/env python3

import sys

args = sys.argv[1:]


if len(args) < 1 or len(args) > 3:
    print("You must provide 1, 2, or 3 interger arguments.", file=sys.stderr)
    sys.exit(1)

nums = []

for arg in args:
    try:
        nums.append(int(arg))
    except:
        print(f"The argument \"{arg}\" is not an interger, You must provide intergers as arguments.", file=sys.stderr)
        sys.exit(0)


if len(nums) == 1:
    for i in range(nums[0]):
        print(i)
elif len(nums) == 2:
    for i in range(nums[0], nums[1]):
        print(i)
else: # we know there are 3 args here.
    for i in range(nums[0], nums[1], nums[2]):
        print(i)
