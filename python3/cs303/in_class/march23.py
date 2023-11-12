'''
A die with 5 faces. Each face has a number on it: 1, 2, 3, 4, 5.
Experiment: Throw the die you look at the face that is down.
            The number on that face is the outcome of the experiment.


outcome     probability
    1          3 / 10
    2          3 / 10
    3          2 / 10
    4          1 / 10
    5          1 / 10

problem: Write pythin program that will run the experiment 10000
times and computer the average outcome (expected value of the outcome).

    Add up all the 10000 outcomes and divide by 10000.
'''
import random

n2out = {1:1, 2:1, 3:1, 4:2, 5:2, 6:2, 7:3, 8:3, 9:4, 10:5}

s = 0
for i in range(10000):
    n = random.randint(1, 10)
    # convert n to an outcome
    out = n2out[n]
    s += out
print(s / 10000)
