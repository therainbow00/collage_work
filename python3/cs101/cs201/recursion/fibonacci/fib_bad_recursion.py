#!/usr/bin/env python3

def fib(x, work = 0):
    work += 1
    if x in [0, 1]:
        return x, work
    f_1, work = fib(x - 1, work)
    f_2, work = fib(x - 2, work)

    return f_1 + f_2, work

if __name__ == "__main__":
    print("==== Fibonacci Bad Recursion ===========")

    for i in range(40):
        f, work = fib(i)
        print(f"fib({i}): {f} - Work: {work}")
