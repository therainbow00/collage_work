#A = [30, 20, 10, 50, 60, 3, 40]
#A = [30, 20, 10, 50, 60, 3, 40]
'''
use the right hand number as a pivot
part1 numbers less than the pivot (40)
part2 number greater than or equal to the pivot
'''
A = []
num = int(input('Enter the number of elements in the array: '))
for i in range(num):
    element = int(input('Enter element: '))
    A.append(element)
#print(A)

def partition(A, p, r):
    x = A[r]  # get the pivot
    i = p - 1 #one less than the index where the next 'small' number
              #will be stored
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i] #swap
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1
'''
print(A)
partition(A, 0, 6)
print(A)
'''
print(A)
partition(A, 0, num - 1)
print(A)
