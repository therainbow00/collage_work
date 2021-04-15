l = [-103, 923, 9123, 10, 847]
l.remove(923)
print(l)
l.append(273)
print(l)
print('-------------------------')

for i,item in enumerate(l):
    print(i, item)

import random
print(random.choice(l))
print(random.choice(l))
random.shuffle(l)
print(l)
random.shuffle(l)
print(l)
print(l.index(-103))
