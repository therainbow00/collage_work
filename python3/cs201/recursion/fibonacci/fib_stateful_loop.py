#!/usr/bin/env python3

current_fibs = None

def fib(x, work = 0):
    global current_fibs
    current_fibs = [0, 1]

    while True:
        work += 1
        if x < len(current_fibs):
            return current_fibs[x], work
        i = len(current_fibs)
        f = current_fibs[i - 1] + current_fibs[i - 2]
        current_fibs.append(f)


if __name__ == "__main__":
    print("==== Fibonacci Bad Recursion ===========")

    # for i in range(40):
    #     f, work = fib(i)
    #     print(f"fib({i}): {f} - Work: {work}")

    i = 43
    f, work = fib(i)
    print(f"fib({i}): {f} - Work: {work}")
