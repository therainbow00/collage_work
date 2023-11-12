A = [30, 20, 10, 50, 60, 3, 40]

'''
use the right hand number as a pivot
part1 numbers less than the pivot (40)
part2 number greater than or equal to the pivot
'''

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
    qs(A, pp + 1, r)        #r - (pp + 1) = number of steps

print(A)
print(partition(A, 0, 6))
print(A)
#A, 0, 3;  A, 5, 6
print(partition(A, 0, 3))
print(A)
#A, 0, 3
print(partition(A, 0, 3))
