# Prompt the user to enter a word
# and assign it to the user_word variable.
word_without_vowels = ""

user_word = input("Introduza uma palavra: ")
user_word = user_word.upper()

for letter in user_word:
    # Complete the body of the for loop.
    if (letter == "A"):
        continue
    if (letter == "E"):
        continue
    if (letter == "I"):
        continue
    if (letter == "O"):
        continue
    if (letter == "U"):
        continue
    word_without_vowels = word_without_vowels + letter
print(word_without_vowels)

