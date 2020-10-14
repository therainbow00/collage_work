#!/usr/bin/env python3

# Takes a string message and translate through the provided dictionary.
def dictionaryTranslator(message, di):
    results = ""
    for c in message:
        if c in di.keys():
            results += di[c]
        else:
            results += c
    return results

def parse2CharCryptoString(key_data):
    li = key_data.split("\n")
    crypto_key = {}

    for line in li:
        if line:
            if len(line) == 1:
                line += " "
            crypto_key[line[0]] = line[1]
    return crypto_key

def readfile(file):
    f = open(file, "r")
    s = f.read()
    f.close()
    return file

def writefile(file, data):
    f = open(file, "w")
    f.write(data)
    f.close()

if __name__ == "__main__":
    print(f"Testing {__file__}.")
