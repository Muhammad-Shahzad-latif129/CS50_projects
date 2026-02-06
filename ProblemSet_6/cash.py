def main():
    while True:
        try:
            dollars = float(input("Change: "))
            if dollars >= 0:
                break
        except ValueError:
            continue

    cents = round(dollars * 100)
    number_coins = 0

    while cents > 0:
        if cents >= 25:
            cents -= 25
            number_coins += 1
            
        elif cents >= 10:
            cents -= 10
            number_coins += 1
            
        elif cents >= 5:
            cents -= 5
            number_coins += 1
            
        else:
            cents -= 1
            number_coins += 1
            

    print(number_coins)



if __name__ == "__main__":
    main()
