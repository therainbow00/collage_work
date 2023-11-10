#!/usr/bin/env python3
NOBODY = -1;
import sys;

def main():
    total_size = int(sys.argv[1]) 
    min_size = int(sys.argv[2])
    buddy = [{"pid": NOBODY, "address": 0, "size": total_size}]
    buddy = [{"pid": NOBODY, "address": 0, "size": total_size / 2},
             {"pid": NOBODY, "address": 0 + total_size / 2, "size": total_size / 2}]
    
    size = 
    pid = 1
    
    found = None;
    best_so_far = 0x7fffffff
    for ind, item in enumerate(buddy):
        if item['pid'] == NOBODY:
            if item['size'] < best_so_far and item['size'] >= size:
                best_so_far = ind
                found = ind
    if found == None:
