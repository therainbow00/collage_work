#!/usr/bin/env python3

import Animal

class Cat(Animal.Animal):
    def __init__(self, name = None, meow = "meow"):
        self.name = name
        self.meow_sound = meow
        super().__init__("Cat")

    def meow(self):
        if self.name:
            print(f"(A {self.name} ({self.kind}): {self.meow_sound.capitalize()}, {self.meow_sound}!)")
        else:
            print(f"(A {self.kind}): {self.meow_sound.capitalize()}, {self.meow_sound}!")


if __name__ == "__main__":
    c1 = Cat()
    c2 = Cat("Mittens", "perrr")
