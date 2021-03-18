import random

'''
octahedron
throw the octahedron; One number per face  1, 2, 3, 4, 5, 6, 7, 8
outcomes    probability
    1           3 / 20
    2           2 / 20
    3           4 / 20
    4           1 / 20
    5           5 / 20
    6           3 / 20
    7           1 / 20
    8           1 / 20

run the experiment 10000 times
n = random.randint(1, 20)
d[n]
and count the number of times each outcome happens
'''
d = {1:1, 2:1, 3:1, 4:2, 5:2, 6:3, 7:3, 8:3, 9:3, 10:4, 11:5, 12:5, 13:5, 14:5, 15:5, 16:6, 17:6, 18:6, 19:7, 20:8}
count = [0, 0, 0, 0, 0, 0, 0, 0, 0]

for i in range(10000):
    n = random.randint(1, 10)
    count[d[n]] += 1
print(count)
