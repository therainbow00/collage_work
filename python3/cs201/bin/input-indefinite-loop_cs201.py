#!/usr/bin/env python3

items = []

input("Enter an item to add (Leave blank to quit): ")

while item != "":
    items.append(item)
    item = input("Enter an item to add (Leave blank to quit): ")


print("-------------------")

for item in items:
    print(item)
