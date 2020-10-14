#!/usr/bin/env python3

import sys

arguments = sys.argv[1:]

unsorted_numbers = []

if len(arguments) > 0:
    for argument in arguments:
        floating_point = float(argument)
        unsorted_numbers.append(floating_point)
else:
    answer = input("Enter a number (blank to quit): ")
    while len(answer) > 0:
        floating_point = float(answer)
        unsorted_numbers.append(floating_point)
        answer = input("Enter a number (blank to quit): ")
def merge(a, b, work):
    i = 0
    j = 0
    merged = []
    while i < len(a) and j < len(b):
        work += 2
        work += 1
        if a[i] < b[j]:
            merged.append(a[i])
            i += 1
        else:
            merged.append(b[j])
            j += 1
    work += 1
    if i < len(a):
        for k in range(i, len(a)):
            merged.append(a[k])
    else:
        for k in range(j, len(b)):
            merged.append(b[k])
    return merged, work

def my_sort(unsorted, work = 0):
    sorted = list(unsorted)

    work += 1
    if len(sorted) <= 1:
        return sorted, work

    work += 1
    a = sorted[:len(sorted) // 2]
    b = sorted[len(sorted) // 2:]

    a, work = my_sort(a, work)
    b, work = my_sort(b, work)

    sorted, work = merge(a, b, work)

    return sorted, work

if __name__== "__main__":
    print(f'==== Running "{__file__}" ===="')

    sorted_numbers, work = my_sort(unsorted_numbers)
    python_sorted = list(unsorted_numbers)
    python_sorted.sort()
    print("Unsorted: ")
    print(f'    {unsorted_numbers}')
    print("Sorted: ")
    print(f'    {sorted_numbers}')
    print("Python_sorted")
    print(f'    {python_sorted}')
    if sorted_numbers == python_sorted:
        print("Sort SUCCEDED!")
    else:
        print("Sort FAILD!")
    print(f"The list of length {len(unsorted_numbers)} required {work} units of work to sort.")
    timeComplexity = "n * log(n)"

    print(f"The time complexity of this sort is Big-O({timeComplexity})")

    # print(merge([], []))
    # print(merge([1], []))
    # print(merge([], [1]))
    # print(merge([1], [2]))
    # print(merge([1, 2], [3]))
    # print(merge([1], [2, 3]))
    # print(merge([1, 2], [3, 4]))
    # print(merge([1, 2, 3], [4, 5]))
    # print(merge([1, 2], [3, 4, 5]))
