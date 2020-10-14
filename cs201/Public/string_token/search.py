#!/usr/bin/env python3

file = open("data.dat", "r")
data = file.read()
file.close()

search_character = '"'
escape_chr = "\\"

mode = "searching" # "searching" | "collecting" | "escaping"

token = ""
tokens = []

for character in data:
    print(character)

for i in range(len(data)):
    character = data[i]
    if character == search_character:
        if mode == "searching":
            mode = "collecting"
            token = character
        elif mode == "collecting":
            mode = "searching"
            token += character
            tokens.append(token)
        elif mode == "escaping" and escape_character == character:

        print(i, character)
    else: # chr is NOT a "
        if mode == "collecting":
            token += character


print(tokens)
