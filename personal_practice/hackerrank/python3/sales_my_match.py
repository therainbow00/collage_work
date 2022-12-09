#!/bin/python3

import math
import os
import random
import re
import sys


'''
Complete the 'sockMerchant' function below.

The function is expected to return an INTEGER.
The function accepts following parameters:
    1. INTEGER n
    2. INTEGER_ARRAY ar
'''
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
    check = 0
    array_length = len(ar)
    biggest = 0
    pairs = 0
    count = 0
    if 1 <= n <= 100:
        ar.sort()
        color = 0
        while color < array_length:
            if 1 <= ar[color] <= 100:
                if ar[color] > biggest:
                    biggest = ar[color]
            color += 1

        for i in range(1, biggest + 1, 1):
            count = 0
            check = 0
            for j in range(array_length):
                if ar[j] == i:
                    count += 1
                    check = 1
            if check > 0:
                    pairs += int (count / 2)
        return pairs


#fptr = open(os.environ['OUTPUT_PATH'], 'w')
if __name__ == "__main__":

    n = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    #fptr.write(str(result) + '\n')
    print(str(result))

    #fptr.close()
