#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sockMerchant' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY ar
#
'''
There is a large pile of socks that must be paired by color. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.

Example


There is one pair of color 1 and one of color 2. There are three odd socks left, one of each color. The number of pairs is .

Function Description

Complete the sockMerchant function in the editor below.

sockMerchant has the following parameter(s):

int n: the number of socks in the pile
int ar[n]: the colors of each sock
Returns

int: the number of pairs
Input Format

The first line contains an integer , the number of socks represented in .
The second line contains n space-separated integers, ar[i], the colors of the socks in the pile.

Constraints
1 <= n <= 100
1 <= ar[i] <= 100 where 0 <= i < n
Sample Input

STDIN                       Function
-----                       --------
9                           n = 9
10 20 20 10 10 30 50 10 20  ar = [10, 20, 20, 10, 10, 30, 50, 10, 20]
Sample Output

3
'''

def sockMerchant(n, ar):
    paris = []
    paris_length = len(paris)
    pairs_count = 0
    count = 0
    if 1 <= n <= 100:
        for color in range(n):
            if 1 <= ar[color] <= 100:
                if paris_length < 1:
                    paris.append(ar[color])
                    #return paris_length
                else:
                    for index in range(paris_length):
                        if paris[index] == ar[color]:
                            count += 1
                        else:
                            paris.append(ar[color])
                            print(paris[index], end='')
                            print(': ' + count)
                        #print(paris[index])
                '''
                for color1 in range(1, n):
                    if 1 <= ar[color1] <= 100:
                        if ar[color] == ar[color1]:
                            paris.append(ar[color1])
                paris.append(ar[color])
                '''
        return paris


#fptr = open(os.environ['OUTPUT_PATH'], 'w')

n = int(input().strip())

ar = list(map(int, input().rstrip().split()))

result = sockMerchant(n, ar)

#fptr.write(str(result) + '\n')
print(str(result))

#fptr.close()
