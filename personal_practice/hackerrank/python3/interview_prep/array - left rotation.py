#usr/bin/env python
'''
A left rotation operation on an array shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1, 2, 3, , 4, 5], then the array would become [1, 4, 5, 1, 2]. Note that the lowest index item moves to the highest index in a rotation. This is called a circular array.

Given an array a of n integers and a number, d, perform d left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.

Function Description

Complete the function rotLeft in the editor below.

rotLeft has the following parameter(s):

int a[n]: the array to rotate
int d: the number of rotations
Returns

int a'[n]: the rotated array
Input Format

The first line contains two space-separated integers n and d, the size of a and the number of left rotations.
The second line contains n space-separated integers, each an a[i].

Constraints

1 <= n <= 10^5
1 <= d <= n
1 <= a[i] <= 10^6

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4
'''

import math
import random
import re
from collections import deque

#
# Complete the 'rotLeft' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER d
#

def rotLeft(a, d):
    # Write your code here
    a = deque(a)
    list = []
    for i in range(len(a) - 1, -1, -1):
        #print(len(a))
        #print(i - d)
        #print(a[-1])
        pass
    a.rotate(-4)
    print(a)
    
    '''
    for i in range(0, n):    
        #Stores the first element of the array    
        first = a[0]  
        
        for j in range(0, len(a)-1):    
            #Shift element of array by one    
            a[j] = a[j + 1]    
            
        #First element of array will be added to the end    
        a[len(a) - 1] = first
    '''    #print(a)

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    d = int(first_multiple_input[1])

    a = list(map(int, input().rstrip().split()))

    result = rotLeft(a, d)

    #print(' '.join(map(str, result)))
    #print('\n')
