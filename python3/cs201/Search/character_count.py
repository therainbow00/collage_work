#!/usr/bin/env python3

import sys
from check_match import check_match

arguments = sys.argv[1:]

file = open(arguments)
file_read = file.read().replace("\r", "").strip()
file.close()

pattern = "ata"
pattern_index = 0
pattern_chr = pattern[0]
matched_indices = []

for search_index in range(len(file_read) - len(pattern) + 1):
    search_chr = file_read[search_index]
    potentail_match = pattern_chr == search_chr
    search_data_long_enough = not (len(file_read) - search_index < len(pattern))
    if potentail_match and search_data_long_enough: # Potentail Match
        if check_match(file_read, search_index, pattern):
            matched_indices.append(search_index)

print(f"Data: {file_read}")
print(f"\nPattern: {pattern}")
print(f"Matches: {len(matched_indices)}")
print(f"Indices: {matched_indices}")
