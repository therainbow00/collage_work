#!/usr/bin/env python3

my_sum = 0

for i in range(1, 11):
    my_sum += 3 * i

print(my_sum)



def summation(i, n):
    if i == n + 1:
        return 0
    return 3 * i + summation(i + 1, n)

print(summation(1, 10))
