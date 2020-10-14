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
def swap(list, index1, index2):
    temp = list[index1]
    list[index1] = list[index2]
    list[index2] = temp

def my_sort(unsorted):
    sorted = list(unsorted)
    work = 0
    for i in range(len(sorted) - 1):
        for j in range(i + 1, 0, -1):
            k = j - 1
            work += 1
            if sorted[j] < sorted[k]:
                work += 1
                swap(sorted, j, k)
            else:
                break
    # Algorithm goes here
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
    print("Python sorted")
    print(f'    {python_sorted}')
    if sorted_numbers == python_sorted:
        print("Sort SUCCEDED!")
    else:
        print("Sort FAILD!")
    print(f"The list of length {len(unsorted_numbers)} required {work} units of work to sort.")
    timeComplexity = "n**2"

    print(f"The time complexity of this sort is Big-O({timeComplexity})")
