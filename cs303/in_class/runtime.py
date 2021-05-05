def runtime(n):
    count = 0
    s = 1
    while s < n:
        s = 2*s
        count += 1
        #print('STEP')
    return count
print('n\tnumber of STEPs')
for i in range(1, 10 + 1):
    print(f'{i}\t{runtime(i)}')
