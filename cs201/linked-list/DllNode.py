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

    print("==== Forward ====")
    print(a)
    print(a.next)
    print(a.prev)
    print(b)
    print(b.next)
    print(b.prev)
    print(c)
    print(c.next)
    print(c.prev)
    print(a.next.value)
    print(a.next.next)
    print(a.next.prev.next.prev.next.prev.next.prev)
    b.next = c
    c.prev = b

    print("==== Mimic DLL ======")

    start = a
    _length = 3
    end = c

    print(start.value)
    print(end.value)
    print(_length)

    new_node = Node("new")
    end_node = end
    end_node.next = new_node
    new_node.prev = end_node

    end = new_node

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
