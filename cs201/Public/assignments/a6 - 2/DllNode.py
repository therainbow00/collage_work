#!/usr/bin/env python3

class Node:
    def __init__(self, val):
        self.value = val
        self.prev = None
        self.next = None

if __name__ == "__main__":
    a = Node("a")
    b = Node("b")
    c = Node("c")

    a.next = b
    b.prev = a
    b.next = c
    c.prev = b

    start = a
    _length = 3
    end = c

    print("=== Forward ===")

    node = start

    while node != None:
        print(node.value)
        node = node.next

    print("=== Backward ===")

    node = end

    while node != None:
        print(node.value)
        node = node.prev
