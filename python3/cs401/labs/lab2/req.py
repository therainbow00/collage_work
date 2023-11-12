#!/usr/bin/env python3

import urllib.request

def data():
    with urllib.request.urlopen("https://cs.indstate.edu/~lmay1/assets/rig.txt") as req:
        req_data = req.read().decode("utf-8")
    return req_data
if __name__ == "__main__":
    print(data())
