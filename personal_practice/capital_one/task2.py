#!/usr/bin/env python3
import re
def solution(a, n):
    b = [0] * n
    a_length = len(a)
    test = True
    count = 0
    for i in range(n):
        if a[i].isnumeric() and a[n - (i + 1)].isnumeric():
            if i + 1 == n - 1:
                b[i] = int(a[i])
                break
            elif test == True:
                b[i] = int(a[i])
                int_element = int(a[i])
                del int_element
                test = False
                count += 1
            else:
                b[i] = int(a[n - count])
                int_element1 = int(a[n - count])
                del int_element1
                test = True
                #return b
            #test = True
            #return b
            #test = False
            #return b
        #return b
        else:
            continue
    print(a, end=' ')
    print()
    return b

n = int(input())
a = input()
new_a = re.sub("[^0-9]", "", a)
print(solution(new_a, n))
