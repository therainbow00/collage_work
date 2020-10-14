#!/usr/bin/env python3

import Animal

class Dog(Animal.Animal):
    def __init__(self, name = None, bark = "bark"):
        self.name = name
        self.bark_sound = bark
        super().__init__("Dog")

    def bark(self):
        if self.name:
            print(f"{self.name}: {self.bark_sound.capitalize()}, {self.bark_sound}!")
        else:
            print(f"(A {self.kind}): {self.bark_sound.capitalize()}, {self.bark_sound}!")

if __name__ == "__main__":
    d1 = Dog()
    d1 = Dog("Fido", "woof")

    d1.bark()
    d2.bark()
