/*
    CS50x - Intro to Computer Science
    Programming in C
    WEEK 1 - Problem Set: Credit
    --------------------------------

        The `credit` program determines whether a provided credit card number is valid according to Luhn’s algorithm.

    The program prompts the user for a credit card number and then reports (via `printf`) whether it is a valid American Express, MasterCard, or Visa card number, according to the definitions of each’s format.

    American Express uses 15-digit numbers, starting with 34 or 37.
    MasterCard uses 16-digit numbers, starting with 51, 52, 53, 54, or 55.
    Visa uses 13- and 16-digit numbers, starting with 4.

    The program’s output should be exactly as follows:
    
    - `AMEX\n` for an American Express card
    - `MASTERCARD\n` for a MasterCard
    - `VISA\n` for a Visa card
    - `INVALID\n` for an invalid card

    Luhn’s Algorithm:
    1. Multiply every other digit by 2, starting with the number’s second-to-last digit.
    2. Add those products' digits together.
    3. Add the sum to the sum of the digits that weren’t multiplied by 2.
    4. If the total’s last digit is 0, the number is valid!
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int cc_length(long int cc_number);
int check_cc_type(long int cc_number, int length);
bool check_cc_validity(long int cc_number);

int main(void)
{
    // Prompt user for credit card number (without spaces or dashes).
    long int cc_number;
    
    printf("Enter credit card number without dashes or spaces: ");
    scanf("%ld", &cc_number);
    int length = cc_length(cc_number);
    check_cc_type(cc_number, length);

    return 0;
}

// Credit card length:
int cc_length(long int cc_number)
{
    int length = 0;
    while(cc_number > 0)
    {
        cc_number /= 10;
        length++;
    }
    return length;
}

// Credit card type:
bool check_cc_validity(long int cc_number)
{
    // Check if the credit card number is valid.
    int sum = 0;
    int removed_digit = 0;

    while(cc_number > 0)
    {
        // Get the last digit of the credit card number.
        int digit = cc_number % 10;
        removed_digit++;

        if (removed_digit % 2 == 0)
        {
            sum += (digit * 2 > 9) ? (digit * 2 - 9) : digit * 2;
        }
        else
        {
            sum += digit;
        }
        // Remove the last digit of the credit card number.
        cc_number /= 10;
    }
    return (sum % 10 == 0);
}

int check_cc_type(long int cc_number, int length)
{
    bool is_valid = check_cc_validity(cc_number);
    if (is_valid)
    {
        // Get the first digit of the credit card number.
        int prefix_1 = cc_number / (long long) pow(10, length - 1);
        // Get the first two digits of the credit card number.
        int prefix_2 = cc_number / (long long) pow(10, length - 2);

        if ((prefix_2 == 34 || prefix_2 == 37) && length == 15)
        {
            printf("AMEX\n");
            return 0;
        }
        if ((prefix_2 >= 51 && prefix_2 <= 55) && length == 16)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        if ((prefix_1 == 4) && (length == 13 || length == 16))
        {
            printf("VISA\n");
            return 0;
        }
    }
    printf("INVALID\n");
    return 0;
}