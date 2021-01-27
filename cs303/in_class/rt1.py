# prints out the numbers from largest to smallest
#!/usr/bin/env python3
lst = [55, 66, 44, 11, 99]
n = len(lst) # number of items in the lst
while n > 0:
    biggest = lst[0]
    for i in lst:
        if i > biggest:
            biggest = i
    print(biggest)
    lst.remove(biggest)
    print(lst)
