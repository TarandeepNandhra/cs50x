from cs50 import get_int

def main():
    while True:
        n = get_int("Height:")
        if n > 0 or n < 9:
            break

    for i in range(n):
        dot(n+1-i)
        hash(i+1)
        print("  ", end="")
        hash(i+1)
        print()


def hash(a):
    for i in range(a):
        print("#", end = "")
    return 0

def dot(b):
    for i in range(b):
        print(" ", end = "")

main()
