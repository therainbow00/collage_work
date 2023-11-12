#!/usr/bin/env python3

import re
from req import data

def search(text, regex, start_line = 0, end_line = 0):
    r = re.compile(regex, re.I)
    list = []

    lines = text.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        match = r.search(line)
        if match:
            start = i - start_line
            end = i + 1 + end_line
            list.append("\n".join(lines[start:end]))
    return list

if __name__ == '__main__':
    start = 1
    end = 3
    li = search(data(), r"^(m)[a-z]+ (m)", start_line = start, end_line = end)

    print("\n\n".join(li))
    print()


    print("=======================")
    print("Number of matches:", len(li))
    print("=======================")
