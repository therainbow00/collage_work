import random

lst = [0, 0, 0, 0, 0, 0, 0]
for i in range(60000):
    outcome = random.randint(1, 6)
    lst[outcome] += 1

print(lst)
