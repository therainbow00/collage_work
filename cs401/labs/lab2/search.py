#!/usr/bin/env python3
import re

def find(text, regex, start_line = 0, end_line = 0):
    r = re.compile(regex)
    list = []

    lines = text.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        if r.search(line):
            start = i - start_line
            end = i + 1 + end_line
            list.append("\n".join(lines[start:end]))
    return list
