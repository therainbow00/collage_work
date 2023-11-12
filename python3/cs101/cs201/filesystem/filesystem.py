#!/usr/bin/env python3

import os

def list_dirs(dirs):
    for d in dirs:
        subdirs = []
        d_contents = os.listdir(d)
        for item in d_contents:
            abs_item = os.path.join(d, item)
            if os.path.isdir(abs_item):
                subdirs.append(abs_item)
        list_dirs(subdirs)
        for d2 in subdirs:
            print(d2)

list_dirs(["/u1/class/cs20118"])

# current_dir = "/u1/class/cs20118"
#
# dir_contents = (os.listdir(current_dir))
# print(dir_contents)
#
# dirs = []
# others = []
#
# for item in dir_contents:
#     item_path = os.path.join(current_dir, item)
#     print(item_path)
#     if os.path.isdir(item_path):
#         dirs.append(item_path)
#     else:
#         others.append(item_path)
