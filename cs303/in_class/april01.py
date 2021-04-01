'''
quiz6
    (recursion)
    partition function
        Given: array A = [40, 20, 70, 25, 50, 60, 55, 19, 45]
               partition(A, 0, 8)
               code for partition
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

        Show what happens to array A
array A = [40, 20, 70, 25, 50, 60, 55, 19, 45]
p = 0
r = 8

x = 45
i = -1, 0, 1, 2, 3
j = 0, 1, 2, 3, 4, 5, 6, 7
array A = [40, 20, 25, 70, 50, 60, 55, 19, 45]
array A = [40, 20, 25, 19, 50, 60, 55, 70, 45]
array A = [40, 20, 25, 19, 45, 60, 55, 70, 50]

==================================================

array A = [50, 60, 20, 30, 25, 40, 55, 19, 45] j = 0, 1, 2, i = 1;
partition(A, 0, 8)
x = 45
p = 0
r = 8
i = (p - 1) = -1
j = 0
A = [20, 60, 50, 30, 25, 40, 55, 19, 45] j = 3, i = 1
A = [20, 60, 50, 30, 25, 40, 55, 19, 45] j = 4, i = 2
A = [20, 30, 25, 60, 50, 40, 55, 19, 45] j = 5, i = 3
A = [20, 30, 25, 40, 50, 60, 55, 19, 45] j = 6, 7; i = 4
A = [20, 30, 25, 40, 19, 60, 55, 50, 45] j = 6, 7; i = 4
A = [20, 30, 25, 40, 19, 45, 55, 50, 60]
'''
