#!/usr/bin/env python3

# Get Key Data
f = open("crypto.key", "r")
key_data = f.read()
f.close()

# Parse Key Data into dict
li = key_data.split("\n")
print(li)
crypto_key = {}

for line in li:
    print(line, li)
    if line:
        print(line)
        if len(line) == 1:
            line += " "
        crypto_key[line[0]] = line[1]
        print(crypto_key[line[0]], line[1])

# Get the Message Data
f = open("message.txt", "r")
message_data = f.read()
f.close()

# Encrypt
results = ""
for c in message_data:
    if c in crypto_key.keys():
        results += crypto_key[c]
    else:
        results += c


# Output to File
f = open("encrypted.txt", "w")
f.write(results)
f.close()
