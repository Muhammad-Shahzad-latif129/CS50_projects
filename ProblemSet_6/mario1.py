while True:
    n = int(input("Height: "))
    if n >= 1 and n <= 8:
        break

def main():
    pyramid(n)

def pyramid(n):
    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end="")
        for x in range(i + 1):
            print("#",end="")
        print()

if __name__ == "__main__":
    main()
