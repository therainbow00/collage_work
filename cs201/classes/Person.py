#!/usr/bin/env python3

import Animal
import Dog

class Person(Animal.Animal):
    def __init__(self, name, pets = None):
        super().__init__("human")
        self.name = name
        if not pets:
            self.pets = []
        else:
            self.pets = pets

    def say_hello(self):
        print(f"{self.name} ({self.kind}): Hi, my name is {self.name}!")

    def add_pet(self, pet):
        self.pets.append(pet)

    def walk_pets(self):
        for pet in self.pets:
            msg = ""
            if pet.name:
                msg += pet.name + " "
            msg += f"({pet.kind}) is on a walk."
            print(msg)


if __name__ == "__main__":

    li = ["Alice", "Bob", "Carl", "David", "Ellen"]

    people = {}
    for name in li:
        people[name] = Person(name)

    fido = Dog.Dog(name = "fido", bark = "yip")
    people["Alice"].add_pet(fido)
    people["Bob"].add_pet(fido)

    # other stuff
    for name in people.keys():
        person = people[name]
        person.say_hello()
        person.walk_pets()
