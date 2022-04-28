#!/usr/bin/env python3

number = [1, 8, 3, 7, 5, 12, 10]
answer = []
for i in range(len(number)):
    if i % 2 == 0:
        answer.append(number[i])
print(answer)
