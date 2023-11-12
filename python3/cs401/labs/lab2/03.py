#!/usr/bin/env python3

import re
import urllib.request

r = re.compile(r"\(")

maches = 0

for line in urllib.request.urlopen("https://cs.indstate.edu/~lmay1/assets/rig.txt"):
    line_data = line.decode("utf-8")
    if r.findall(line_data):
        print(line.strip().decode())
        maches += 1

print("=======================")
print("Number of maches:", maches)
print("=======================")
