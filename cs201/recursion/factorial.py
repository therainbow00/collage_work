#!/usr/bin/env python3

def factorial(x):
    print("Winding up", "x", x)
    if x == 1: # BASE CASE  - prevents infinite recursion - stack goes boom
        result = 1
    else:
        result = x * factorial(x - 1)
    print("Winding down", "x", x)
    return result

print(f"Five factorial is {factorial(5)}")
