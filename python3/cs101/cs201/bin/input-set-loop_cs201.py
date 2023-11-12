#!/sur/bin/env python3

num_str = input("Enter the number of times you'd like to input: ")

items = []

for i in range(int(num_str)):
    print(f"Currnet items: {items}")
    item = input("Enter an intem: ")
    is_correct = input(f"\"{item}\" is this correct (Y/n)? ").lower()
    while is_correct != "y" and is_correct != "":
        item = input("Enter an intem: ")
        is_correct = input(f"\"{item}\" is this correct (Y/n)? ").lower()
    items.append(item)

print("-------------")

for item in items:
    print(item)

print("=============")

for i in range(len(items)):
    print(str(i) + ")", items[i])
