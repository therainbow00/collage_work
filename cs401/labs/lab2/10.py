#!/usr/bin/env python3

import re
from req import data

def search(text, regex, start_line = 0, end_line = 0):
    r = re.compile(regex, re.I)
    #list = []
    matches = 0

    lines = text.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        match = r.search(line)
        if match:
            matches += 1
            start = i - start_line
            end = i + 1 + end_line
            print(lines[start])
            print(lines[end])
            print()
    return matches

if __name__ == '__main__':
    start = 1
    end = 1

    print("Number of matches:", search(data(), r"^[0-9].*(east|south|west|north)", start_line = start, end_line = end))
