#!/usr/bin/env python3

import os

#for item in dir():
#    print(item)

print("__fie__", __file__)
rp = os.path.realpath(__file__)
print("rp", rp)
spript_dir, script_file_name = os.path.split(rp)
print("script_dir", script_dir)
script_dir_name = os.path.basename(script_dir)
print("script_dir_base", script_dir_base)

script_parent = os.path.join(script_dir, "..")
script_parent = os.path.abspath(script_parent)
print("script_parent", script_parent)
