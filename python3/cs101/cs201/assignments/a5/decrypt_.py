#!/usr/bin/env python3

import sys

arguments = sys.argv[1:]

if "--help" in arguments:
    print("Argument 1: cipher key, or creat one.")
    print("Argument 2: message file to be decrypted, or type it")
    print("Argument 3: file for the decrypted message, or it will print on screen")
    sys.exit(0)

if len(arguments) > 0: # if arg 1 provided
    file = open(arguments[0], "r")
    key_file = file.read()
    file.close()
else:
    key_file = input("Manually enter a cipher key: ")

if len(arguments) > 1: # if arg 2 if provided
    file = open(arguments[1], "r")
    input_file = file.read()
    file.close()
else:
    input_file = input("Manually enter a message to encrypt: ")

list = key_file.split("\n")
key_data = {}

for line in list:
    if line:
        key_data[line[1]] = line[0]

message = ""
for character in input_file:
    if character in key_data.keys():
        message += key_data[character]
    else:
        message += character

if len(arguments) > 2: # if arg 3 is provided
    file = open(arguments[2], "w")
    file.write(message)
    file.close()
else:
    print(message)
