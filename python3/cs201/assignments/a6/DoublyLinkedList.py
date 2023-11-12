#!/usr/bin/env python3

from DllNode import Node

class DoubleLinkedList:

    def __init__(self):
        self._length = 0
        self.start = None
        self.end = None

    def __len__(self):
        return self._length

    def get_node(self, index):
        if index >= self._length or index < 0:
            raise IndexError("The DoublyLinkedList Index out of bounds.")
        current_node = self.start
        current_index = 0

        if index < self._length / 2:
            current_node = self.start
            current_index = 0
            while current_index < index:
                current_node = current_node.next
                current_index += 1
            return current_node
        else:
            current_node = self.end
            current_index = self._length - 1
            while current_index > index:
                current_node = current_node.prev
                current_index -= 1
        return current_node

    def get_value(self, index):
        return self.get_node(index).value

    def insert(self, index, val):
        if index > self._length or index < 0:
            raise IndexError("The DoublyLinkedList Index out of bounds.")

        new_node = Node(val)

        if self._length == 0:
            self.start = new_node
            self.end = new_node
            self._length += 1
            return

        if index == 0:
            first = self.start
            self.start = new_node
            new_node.next = first
            first.prev = new_node
            self._length += 1
            return

        if index == self._length:
            last = self.end
            self.end = new_node
            new_node.prev = last
            last.next = new_node
            self._length += 1
            return

        after_node = self.get_node(index)
        before_node = after_node.prev

        before_node.next = new_node
        new_node.prev = before_node
        new_node.next = after_node
        after_node.prev = new_node
        self._length += 1
        return

    def append(self, val):
        index = self._length
        self.insert(index, val)


    def pop(self, index):
        if index > self._length or index < 0:
            raise IndexError("The DoublyLinkedList Index out of bounds.")

        if index == 0:
            first = self.start
            self.start = first.next
            del first
            self._length -= 1
            return

        if index == self._length - 1:
            last = self.end
            self.end = last.prev
            del last
            self._length -= 1
            return

        to_be_removed = self.get_node(index)

        before_node = to_be_removed.prev
        after_node = to_be_removed.next

        before_node.next = after_node
        after_node.prev = before_node

        self._length -= 1
        return

    def remove(self, val):
        if self._length == 0:
            return

        current_node = self.start
        current_index = 0

        while current_node.value != val and current_index < self._length:
            current_node = current_node.next
            current_index += 1
        if current_index == self._length:
            return

        return self.pop(current_index)

    def print_forward(self):
        # print("==== Forward Print ===")
        if self._length != 0:
            current_node = self.start
            current_index = 0
            while current_index < self._length:
                print(current_node.value)
                current_index += 1
                current_node = current_node.next
        # print("==== Forward Print - END ====")

    def print_backward(self):
        # print("==== Backward Print ===")
        if self._length != 0:
            current_node = self.end
            current_index = self._length - 1
            while current_index >= 0:
                print(current_node.value)
                current_index -= 1
                current_node = current_node.prev
        # print("==== Backward Print - END ====")

if __name__ == "__main__":
    print(f"Testing \" {__file__}\"...")

    dll = DoubleLinkedList()
    dll.append("b")
    dll.insert(1, "c")
    dll.insert(0, "a")
    dll.append("d")
    dll.remove("d")

    print("==== Forward ====")
    dll.print_forward()
    print("==== Backward ====")
    dll.print_backward()
    print(dll.pop(len(dll)-1))
    print(dll.pop(len(dll)-1))
    print(dll.pop(len(dll)-1))
