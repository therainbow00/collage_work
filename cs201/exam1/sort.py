import sys

arguments = sys.argv[1:]

sorted = []

if len(arguments) > 0:
    nums_list = []
    for argument in arguments:
        float(arguments)
        nums_list.append(arguments)
else:
    nums_list = []
    numbers = input("Enter a number (leave blank to quit): ")
    while numbers != "":
        float(numbers)
        nums_list.append(numbers)
        numbers = input("Enter a number (leave blank to quit): ")

print(nums_list)

work = 0

def get_lowest():
    lowest = None
    print(f"(lowest: {lowest})")
    for number in nums_list:
        print(f"(number: {number})(nums_list: {nums_list})")
        if lowest == None or number < lowest:
            lowest = number
            print(f"(lowest: {lowest})(numer: {number})")
            global work
            work += 1
    nums_list.remove(lowest)
    print(f"(removed lowest from nums_list: {lowest})")
    return lowest

for values in nums_list:
    print(f"(values: {values})")
    sorted.append(get_lowest())
    print(f"(sorted list: {sorted})")

print(sorted)
print(f"Sorted in: {work} checks")
print("O(n)")
