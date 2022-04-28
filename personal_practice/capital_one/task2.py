#!/usr/bin/env python3
import re
def solution(a, n):
    b = [0] * n
    test = True
    count = 0
    for i in range(n):
        if test == True:
            if a[i].isnumeric():
                b[i] = int(a[count])
                test = False
        elif test == False:
            if a[n - (count + 1)].isnumeric():
                b[i] = int(a[n - (count + 1)])
                test = True
                count += 1
    return b

n = int(input())
a = input()
r = re.compile(r"^[0-9]")
new_a = re.sub(r, "", a)
print(solution(new_a, n))
