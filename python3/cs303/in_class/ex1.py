import random

n2out = {1:1, 2:1, 3:1, 4:2, 5:2, 6:2, 7:3, 8:3, 9:4, 10:5}

s = 0
for i in range(10000):
    n = random.randint(1, 10)
    # convert n to an outcome
    out = n2out[n]
    s += out
print(s / 10000)
print((3 * 1 + 3 * 2 + 2 * 3 + 1 * 4 + 1 * 5) / 10)
