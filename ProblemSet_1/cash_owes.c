#include<stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickles(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompting from the user and also figuring the valid input
    int cents;
    char c;
    while (1)
    {
        printf("Change Owed: ");
        //scanf return the numbers like 1, 2 on secessful if read 
        if(scanf("%i%c", &cents, &c) != 2 || c != '\n')
        {
            printf("Invalid Input. Please enter the valid integers for cents.\n");
            while(getchar() != '\n');
            continue;
        }
        if (cents < 0)
        {
            printf("Enter the valid integer for the cents.\n");
            continue;
        }
        break;
    }
    //End
    //Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);
    //Subtract the value of those quarters from cents
    cents = cents - (quarters * 25);

    //Calculate how many dimes you should give the customer
    int dimes = calculate_dimes(cents);
    //Subtract the value of those dimes from the remaining cents
    cents = cents - (dimes * 10);

    //Calculate how many nickles you should give the customer
    int nickles = calculate_nickles(cents);
    //Subtract the value of those nickles from the remaining cents
    cents = cents - (nickles * 5);
    //Calculate how many pennies you should give the customer
    int pennies = calculate_pennies(cents);
    //Subtract the value of those pennies from the remaning cents
    cents = cents - (pennies * 1);

    //Sum the number of quarters, dimes, nickles, pennies used
    int sum = quarters + dimes + nickles + pennies;
    printf("%i\n", sum);
    return 0;
}

int calculate_quarters(int cents)
{
    //Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    //Calculate how many dimes you should give the customer
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}
int calculate_nickles(int cents)
{
    //Calculate how many nickles you should give the customer

    int nickles = 0;
    while (cents >= 5)
    {
        nickles++;
        cents = cents - 5;
    }
    return nickles;
}
int calculate_pennies(int cents)
{
    //Calculate how many pennies you should give the customer

    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}