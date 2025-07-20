#include<stdio.h>

long long get_long(void);
int sum_of_skipped_digits(long long number);
int length_of_number(long long number);
int first_two_digit(long long number);
int first_digit(long long number);

int main(void)
{
    long long number = get_long();
    long long x = number;
    if (number <= 0 )
    {
        printf("IVALID.\n");
    }
    else
    {
        //Sum of the double of every other numbers from the second-to-last
        int sum = 0;
        int position = 0;
        while (number > 0)
        {
            int digit = number % 10;
            if (position % 2 == 1)
            {
                int doubled = digit * 2;
                sum += (doubled / 10) + (doubled % 10);
            }
            number /= 10;
            position++;
        }
            //sum of the skipped numbers
            int skiped_sum = sum_of_skipped_digits(x);
            //Sum of the skipped numbers and the sum of the double of every numbers from th second-to-last
            int total_sum = skiped_sum + sum;
            //Length of the number
            int length = length_of_number(x);
            //First two digit of the number
            int f_two_digit = first_two_digit(x);
            //First digit for the VISA card
            int f_digit = first_digit(x);
            //Checksum and the print the appropriate card
            if (total_sum % 10 == 0)
            {
                if (length == 15 && (f_two_digit == 34 || f_two_digit == 37))
                {
                    printf("AMEX\n");
                }
                else if (length == 16 && f_two_digit >= 51 && f_two_digit <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else if((length == 13 || length == 16) && f_digit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
    }    
    return 0;    
}
long long get_long(void)
{
    long long number;
    char c;

    while (1)
    {
        printf("Number: ");
        int result = scanf("%lld%c", &number, &c);

        if (result != 2 || c != '\n')
        {
            // Clear any leftover characters from input buffer
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
        }
        else
        {
            return number;
        }
    }
}



int sum_of_skipped_digits(long long number)
{
    int sum = 0;
    int position = 0;
    while (number > 0)
    {
        int digit = number % 10;
        if (position % 2 == 0)
        {
            sum += digit;
        }
        number /= 10;
        position++;
    }
    return sum;
}
int length_of_number(long long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int first_two_digit(long long number)
{
    
    while (number >= 100)
    {
        number = number / 10;
    }
    return number;
}
int first_digit(long long number)
{
    while (number >= 10)
    {
        number /= 10;
    }
    return number;
}