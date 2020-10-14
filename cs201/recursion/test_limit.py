#!/usr/bin/env python3

count = 0

def test_limit():
    global count
    print(count)
    count += 1
    test_limit()

def test_limit2(x):
    print(x)
    return test_limit2(x + 1)


test_limit()
