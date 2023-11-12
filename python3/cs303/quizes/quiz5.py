import random
d = {1:1, 2:1, 3:1, 4:1, 5:2, 6:2, 7:2, 8:3, 9:3, 10:4}

sum = 0
for i in range(10000):
    n = random.randint(1, 10)
    # convert n to an outcome
    outcome = d[n]
    sum += outcome
print(sum / 10000)
print((4 * 1 + 3 * 2 + 2 * 3 + 1 * 4 ) / 10)

'''
lst = [1, 1, 1, 1, 2, 2, 2, 3, 3, 4]
s = 0
for i in range(10000):
    s += random.choice(lst)
print(s / 10000)
'''
