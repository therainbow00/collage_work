import random
array = [[0 for i in range(30)] for j in range(30)]
for i in range(30):
    print(array[i])
for i in range(30):
    x = random.sample(range(30), 2) # pick two vertices out the 30
    if array [x[0]][x[1]]:
        continue
    array[x[0]][x[1]] = 1
    array[x[1]][x[0]] = 1
print('==========================================================================================')
for i in range(30):
    print(array[i])
