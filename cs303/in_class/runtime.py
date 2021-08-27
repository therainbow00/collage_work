def runtime(n):
    count = 0
    for i in range(1, n + 1):
          for j in range(2 * i):
              count += 1
    return count
def runtime1(n):
    count = 0
    for i in range(1, n + 1):
          for j in range(2 * i):
              count = (n + 1) * i
        #print('STEP')
    return count
def runtime2(n):
    count = 0
    for i in range(n):
         for k in range(n):
           count += 1
        #print('STEP')
    return count

print('n\tnumber of STEPs')
for i in range(1, 10 + 1):
    print(f'{i}\t{runtime(i)} - {runtime1(i)}')
print('=======================================')
for j in range(1, 10 + 1):
    print(f'{j}\t{runtime2(j)}')
