#!/usr/bin/env python3

from search import find
from req import data

def lab(regex, before_lines = 0, after_lines = 0):
    rig_data = data()
    res = find(rig_data, regex, start_line = before_lines, end_line = after_lines)
    join_str = "\n\n" if after_lines + before_lines > 0 else "\n"
    print(join_str.join(res))
    return len(res)
