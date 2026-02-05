def main():
    while True: 
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                break
        except ValueError:
            continue
    pyramid(n)

def pyramid(n):
    for i in range(1, n+1):
        for j in range(n - i):
            print(" ", end="")
        for k in range(i):
            print("#",end="")

        print("  ", end="")

        for l in range(i):
            print("#", end="")

        print()

if __name__ == "__main__":
    main()
