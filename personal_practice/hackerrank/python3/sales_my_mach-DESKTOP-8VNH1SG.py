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
    counted = []
    array_length = len(ar)
    #counted_length = len(counted)
    pairs = 0
    count = 0
    same = False
    state = True
    if 1 <= n <= 100:
        color = 0
        while color < array_length:
            #print(color, n)
            if 1 <= ar[color] <= 100:
                temp = ar[color]
                print(temp, ar[color])
                if len(counted) < 1:
                    counted.append(temp)
                    print(counted)
                print(len(counted))
                for i in range(len(counted)):
                    print(counted[i], temp)
                    if counted[i] == temp:
                        print('here')
                        same = True
                        break
                print(counted)
                for j in range(len(counted)):
                    if same == True:
                        break
                    print('here1')
                    counted.append(temp)
                for item in range(array_length):
                    if ar[item] == temp:
                        count += 1
                        print(count)
                #global pairs
                if count % 2 == 0:
                    pairs += count / 2
                print(pairs)
                count = 0
                '''
                for index in range(array_length):
                    print(index, ar[index])
                    if temp == ar[index]:
                        print(temp, ar[index])
                        paris.append(ar[index])
                        print(paris)
                        #del ar[index]
                        print(ar)
                i = 0
                while i < len(ar):
                    print(f'del: {temp}, {ar[i]}')
                    if temp == ar[i]:
                        del ar[i]
                        print('del:', ar)
                        state = False
                    elif state == False:
                        i = 0
                        state = True
                    else:
                        i += 1
                '''
            color += 1
        return pairs


#fptr = open(os.environ['OUTPUT_PATH'], 'w')
if __name__ == "__main__":

    n = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    #fptr.write(str(result) + '\n')
    print(str(result))

    #fptr.close()
