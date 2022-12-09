print("Welcome to Scramble, ENJOY!")
print("An animal word has been scrambled, unscramble it and win the game.")
print("If the answer if correct, than the + sign will appear.")
print("If the answer if incorrect, than the - sign will appear.")
print("All names are case sensitive.")

import sys
import random

animals_names = ["dog", "cat", "mouse", "donkey", "bird", "snake", "fish", "monkey", "pig", "Mussel", "civet", "addax", "hedgehog", "skunk", "shrew", "kangaroo", "opossum", "llama", "bull", "argali", "bison", "starfish", "sloth", "boar"]
answer = random.choice(animals_names)
word = list(answer)
scrambledWord = list(answer)
random.shuffle(scrambledWord)
print(scrambledWord)

correct = 0

usersWord = []

def checkingTheLetters(number):
    if usersWord[number] == word[number]:
        print('----------')
        print('-    +   -')
        print('----------')
        global correct
        correct += 1
    else:
        print('----------')
        print('-    -   -')
        print('----------')

def characterCount(letter):
    if len(letter) > 1:
        print("\n----------------------")
        print("Guess only one letter.")
        print("----------------------")
        sys.exit(0)
    elif letter == "":
        print("You lost, score:", correct, "/", len(word))
        sys.exit(0)

for number in range(len(word)):
    if number <= len(answer):
        guess = input("Guess a letter: ")
        characterCount(guess)
        usersWord.append(guess)
        checkingTheLetters(number)

percent = format(correct / len(word), ".0%")

print("===========================================")
print("Your score:",correct,"/",len(word), "---", percent)
print("===========================================")
