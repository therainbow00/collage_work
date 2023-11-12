#!/usr/bin/env python3

import sys

# if no arguments are passed or if only one is passed than this message prints out
if "--help" in sys.argv:
    print("Must have at least 1 numeric argument (0 - 52) and a file path to run this program.")
    sys.exit(0)

# defines command-line arguments
offset = int(sys.argv[1])
file_path = sys.argv[2]

# stores ascii characters
final_list = []

# adding the ascii characters in a list
for letter in range(65, 90 + 1):
    final_list.append(chr(letter))

for letter in range(97, 122 + 1):
    final_list.append(chr(letter))

# making the key
final_output = ""
for letter in range(len(final_list)):
    key = final_list[letter]
    value = final_list[(letter + offset) % 52]
    final_output += key + value + "\n"

# labels final output
result = final_output

# writting the output of the key into a file
file = open(file_path, "w")
file.write(result)
file.close()
