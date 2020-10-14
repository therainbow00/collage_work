#!/usr/bin/env python3

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.start = None # initisl node

    def add_value(self, value):
        pass



if __name__ == "__main__":
    n0 = Node("a")
    n1 = Node("b")
    n2 = Node("c")

    print(n0.value)
    print(n1.value)
    print(n2.value)

    print(n0.next)
    n0.next = n1
    print(n0.next)

    # n1.next = n2
    n0.next.next = n2

    n = n0
    while n:
        print(n.value)
        n = n.next
