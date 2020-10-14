#!/usr/bin/env python3

# Get Key Data
f = open("crypto.key", "r")
key_data = f.read()
f.close()

# Parse Key Data into dict
li = key_data.split("\n")
crypto_key = {}

for line in li:
    if line:
        if len(line) == 1:
            line += " "
        crypto_key[line[1]] = line[0]

# Get the Message Data
f = open("encrypted.txt", "r")
message_data = f.read()
f.close()

# decrypt the data
results = ""
for c in message_data:
    if c in crypto_key.keys():
        results += crypto_key[c]
    else:
        results += c

# Output to File
f = open("decrypted.txt", "w")
f.write(results)
f.close()
