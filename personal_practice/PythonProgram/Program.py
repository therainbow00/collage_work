print("Welcome to Scramble, ENJOY!")
print("An animal word has been scrambled, unscramble it and win the game.")
print("If you guess the same letter twice, the game ends")
print("Each input must only be 1 character")
print("You must type a character or the game ends")
print("All names are case sensitive.")

import sys
import random

animals_names = ["dog", "cat", "mouse", "donkey", "bird", "snake", "fish", "monkey", "pig", "Mussel", "civet", "addax", "hedgehog", "skunk", "shrew", "kangaroo", "opossum", "llama", "bull", "argali", "bison", "starfish", "sloth", "boar"]
answer = random.choice(animals_names)
word = list(answer)
scrambledWord = list(answer)
random.shuffle(scrambledWord)
print(scrambledWord)
print('_ ' * len(scrambledWord))

correct = 0

usersWord = []

count = 1
word_length = len(word)

characterFound = False

def checkingTheLetters(number, letter):
    if letter == word[number]:
        global correct
        correct += 1

def characterCount(letter):
    if len(letter) > 1:
        print("\n----------------------")
        print("Guess only one letter.")
        print("----------------------")
        sys.exit(0)
    elif letter == "":
        global word_length
        print("You lost, score:", correct, "/", word_length)
        print(usersWord.append(letter))
        sys.exit(0)

done = False
guess = input("Guess a letter: ")
while (guess != 'quit'):
    if len(usersWord) > 0:
        for num in range(len(usersWord)):
            if guess == usersWord[num]:
                characterFound = True
            if characterFound:
                print('-' * 30)
                print('Letter already guessed')
                print('-' * 30)
                sys.exit(0)

    for number in range(word_length):
        if number <= len(answer):
            characterCount(guess)
            checkingTheLetters(number, guess)

    usersWord.append(guess)

    if (count == word_length):
        break
    guess = input("Guess a letter: ")

percent = format(correct / word_length, ".0%")

print("===========================================")
print("Your score:",correct,"/",word_length, "---", percent)
print(f"Guessed letters: {usersWord}")
print(f"Word: {answer}")
print("===========================================")

