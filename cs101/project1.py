#Project 1: Hangman	9/18

import random
import io
import sys


with open("/Users/calebhwang/Fall2025/cs101/1000random-words/10000words") as f:
    words = f.read().split()   # split text into list of words
    word = random.choice(words)

letters = list(word)
length = len(letters)
counter = 20
captured = "1"
letter_guess = "2"
guesses = []
word_guess = "3"

while (counter >= 1):
    if counter < 20:
        print("Guesses so far: ", end="")

    for n in guesses:
        print(n, end=" ")
    print("\n")

    a_guess = input("\nGuess a letter: ")

    if counter == 0:
        print(f"Out of tries. The word was: {word}.")
        sys.exit()

    elif len(a_guess) != 1:
        print("Invalid input. Type 1 character.")
        counter = counter
        print(f"Still {counter} tries left.")

    elif word != word_guess:
        letter_guess = a_guess
        for i in range(0, length):
            if letter_guess == letters[i]:
                print(f"{letter_guess} ", end="")

            elif letters[i] in guesses:
                print(f"{letters[i]} ", end="")
            else:
                print("_ ", end="")
        counter = counter - 1
        guesses.append(letter_guess)

        buffer = io.StringIO()
        sys.stdout = buffer
        sys.stdout = sys.__stdout__
        captured = buffer.getvalue()
        word_guess = captured.replace(" ","")
        print(f"\n{counter} tries left.")
    else:
        print(f"You guessed it. The word was: {word}!")
