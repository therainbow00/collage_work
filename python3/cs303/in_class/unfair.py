'''
03/17

an experiment : Throw a die
    possible outcomes: 1, 2, 3, 4, 5, 6
    if the die is "fair", then pr(2) = 1 / 6
                               pr(5) = 1 / 6

    fair: each outcome is as likely as any other outcome
        total probability = 1. There are six possible outcomes;
        so the probability of each out come is 1 / 6.
        The outcomes are equi-probable.

repeat the experiment lots of times. About 1 / 6 of the times, the
outcome will be a 2

suppose the die is NOT "fair"
n = random.randint(1, 10)
outcome  probability
    1       2 / 10   n in [1, 2]
    2       1 / 10   n in [3]
    3       3 / 10   n in [4, 5, 6]
    4       1 / 10   n in [7]
    5       1 / 10   n in [8]
    6       2 / 10   n in [9, 10]
=====================
"fair"

fair.py
outcome = random.randint(1, 6)
==============================
problem write a program whose outcomes have the probabilies above.
'''
'''
import random

#file: unfair.py
n = random.randint(s, e) # makes numbers, n, so that s <= n <= e
n = random.randint(1, 10) # makes numbers, n, so that s <= n <= e
#1, 2, 3, 4, 5, 6, 7, 8, 9, 10   comes out of random.randint(1, 10)
                                #these numbers are equi-probable
'''
'''
consider the set {1, 2}. pr({1, 2}) = 2 / 10
    make this set (event) correspond to outcome = 1

the set {3} pr(n == 3) 1 / 10
    make this set (event) correspond to outcome = 2

the set {4, 5, 6} pr(n in [4, 5, 6]) is 3 / 10
    make this set (event) correspond to outcome = 3

the set {7} pr(n in [7]) is 1 / 10
    make this set (event) correspond to outcome = 4

the set {8} pr(n in [8]) is 1 / 10
    make this set (event) correspond to outcome = 5

the set {9, 10} pr(n in [9, 10]) is 2 / 10
    make this set (event) correspond to outcome = 6


========================
'''
import random

d = {1:1, 2:1, 3:2, 4:3, 5:3, 6:3, 7:4, 8:5, 9:6, 10:6}
count = [0, 0, 0, 0, 0, 0, 0]

for i in range(10000):
    n = random.randint(1, 10)
    count[d[n]] += 1
print(count)
