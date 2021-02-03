from cs50 import get_float

cent = get_float("Change owed: ")
total = 0
c = 0

def main():

    cents = round(int(cent * 100))

    change(25, cents)
    change(10, cents)
    change(5, cents)
    change(1, cents)

    print(f"Number of coins needed: {c}")

def change(coin, cents):
    global total
    global c
    while total < (cents - coin + 1):
        total += coin
        c += 1

main()
