print("Welcome to Scramble, ENJOY!")
print("An animal word has been scrambled, unscramble it and win the game.")
print("If you guess the same letter twice, the game ends")
print("Each input must only be 1 character")
print("You must type a character or the game ends")
print("All names are case sensitive.")

import sys
import random

animals_names = [ "lion", "Elephant", "tiger", "Giraffe", "kangaroo", "zebra", "cheetah", "Dolphin", "koala", "rhinoceros", "Penguin", "jaguar", "gazelle", "hippopotamus", "leopard", "squirrel", "crocodile", "Eagle", "armadillo", "platypus", "buffalo", "antelope", "Albatross", "gorilla", "otter", "chameleon", "hedgehog", "Mongoose", "parrot", "Panda", "vulture", "seagull", "mongoose", "whale", "koala", "Pangolin", "dolphin", "octopus", "llama", "quokka", "iguana", "cockatoo", "orca", "lemur", "macaw", "sloth", "okapi", "quokka", "yak", "Puffin", "firefly", "giraffe", "robin", "iguana", "meerkat", "humpback", "ostrich", "lynx", "ocelot", "marmoset", "jellyfish", "warthog", "yak", "numbat", "panther", "rabbit", "vulture", "penguin", "Armadillo", "hedgehog", "chameleon", "flamingo", "pelican", "zebu", "llama", "lynx", "narwhal", "rooster", "hamster", "eagle", "toucan", "starling", "woodpecker", "weasel", "quail", "dromedary", "ostrich", "tarsier", "marmoset", "jaguar", "pangolin", "impala", "elephant", "parrot", "dolphin", "antelope", "rhinoceros", "vulture", "yak" ]
answer = random.choice(animals_names)
word = list(answer)
scrambledWord = list(answer)
random.shuffle(scrambledWord)

print("_ " * len(scrambledWord))

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
        print("-" * 30)
        print(" Guess only one letter.")
        print("-" * 30)
        sys.exit(0)
    elif letter == "":
        global word_length
        print("You lost, score:", correct, "/", word_length)
        print(f"Guessed letters: {usersWord}")
        sys.exit(0)


guess = input("Guess a letter: ")
while guess != "quit":
    characterCount(guess)
    
    if guess.isdigit():
        print("-" * 50)
        print(f" Guess must be a letter, score: {correct}/{word_length}")
        print("-" * 50)
        sys.exit(0)
    elif len(usersWord) > 0:
        for num in range(len(usersWord)):
            if guess == usersWord[num]:
                characterFound = True
            if characterFound:
                print("-" * 30)
                print(" Letter already guessed")
                print("-" * 30)
                sys.exit(0)

    for number in range(word_length):
        if number <= len(answer):
            checkingTheLetters(number, guess)

    usersWord.append(guess)

    if count == word_length:
        break
    count += 1
    guess = input("Guess a letter: ")

percent = format(correct / word_length, ".0%")

print("===========================================")
print(" Your score:", correct, "/", word_length, "---", percent)
print(f" Guessed letters: {usersWord}")
print(f" Word: {answer}")
print("===========================================")
input('Type anything to exit...')