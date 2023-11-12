#!/usr/bin/env python3

import sys
import os


rp = os.path.realpath(__file__)
spript_dir, script_file_name = os.path.split(rp)
script_dir_name = os.path.basename(script_dir)
script_parent = os.path.join(script_dir, "..")
script_parent = os.path.abspath(script_parent)


args = sys.argv[1:]

if len(args) < 1:
    print("Must prvide a path t a new file.", file=sys.stderr)
    sys.exit(0)

template_file = os.path.join(script_parent, "python3_template.py")
f = open(template_file, "r")
template_data = f.read()
f.close()

f = open(arg[0], "w")
f.write(template_data)
f.close()

def main():
    pass



if __name__ == "__main__":
    main()
