#!/usr/bin/env python3

import sys

sysargs = sys.argv[1:]

# Test case
# /argparse.py -alfD -b --input-file=~/Desktop/in.txt --output-file=~/Desktop/out.txt arg1 arg2 arg3

# Result
# flags = ["a", "l", "f", "D"]
# kargs = {
#    "input-file": "~/Desktop/in.txt",
#    "output-file": "~/Desktop/out.txt",
# }
#args = ["arg1", "arg2", "arg3"]

flags = []
krags = {}
args = []

def get_arg_type(arg):
    t = "arg"
    if len(arg) > 2 and arg[:2] == "--":
        t = "karg"
    elif len(arg) > 1 and arg[0] == "-":
        t = "flag"
    return t

def parse_flag(arg):
    for c in arg[1:]:
        flags.append(c)

def parse_krags(arg):
    li = arg[2:].split("=")
    krags[li[0]] = li[1]

def parse_args(arg):
    return arg

for arg in sysargs:
    arg_type = get_arg_type(arg)
    print(arg, arg_type)
    if arg_type == "flag":
        parse_flag(arg)
    elif arg_type == "krag":
        parse_krags(arg)
    else:
        args.append(arg)

print("flags", flags)
print("krags", krags)
print("args", args)

allowed_flags = ["a", "h", "B"]

for f in flags:
    if f not in allowed_flags:
        print(f"The flag '{f}' is not an allowed option.", file=sys.stderr)
        sys.exit(1)
