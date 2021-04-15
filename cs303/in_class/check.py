import random

def partition(A, p, r):
    x = A[r]  # get the pivot
    i = p - 1 #one less than the index where the next 'small' number
              #will be stored
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]  #swap
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

def qs(A, p, r):                # r - p = number steps from p to r
    if p >= r: #time to stop
        return
    pp = partition(A, p, r) #pivot position
    qs(A, p, pp - 1)        #pp - 1 - p = number of steps; Smaller than r - p
    qs(A, pp + 1, r)

A = [x for x in range(1, 101)]
random.shuffle(A)
print(A)
'''
11 is somewhere, 15 is somewhere  11, 12, 13, 14, 15
pr(11 and 15 will be compared) is 2 / 5

run the experiment 1000 times
'''
for e in range(1000):
    random.shuffle(A)
    qs(A, 0, 100)
    #change partition so it counts when 11 and 15 get compared
print(count / 1000)
