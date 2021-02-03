from cs50 import get_string

s1 = get_string("Text: ")
#make string lower so easier to compare in loop

s = s1.lower()

letters = 0
words = 1
sentences = 0
sentence_end = {'!', '.', '?'}


for c in s:
    if "a" <= c <= "z":
        letters+= 1
    elif c == ' ':
        words+= 1
    elif c in sentence_end:
        sentences += 1

print(f"Number of letters: {letters}")
print(f"Number of words: {words}")
print(f"Number of sentences: {sentences}")

index = (0.0588 * ((letters/words)*100)) - (0.296 * ((sentences/words))*100) - 15.8

if index < 1:
    print("Before Grade 1")
elif index < 16:
    print(f"Grade {round(index)}")
else:
    print("Grade 16+")
