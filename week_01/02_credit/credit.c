#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int cc_length(long int cc_number);
int check_cc_type(long int cc_number, int length);
bool check_cc_validity(long int cc_number);

int main(void)
{
    long int cc_number = 0;
    
    printf("Enter credit card number (without dashes or spaces): ");
    scanf("%ld", &cc_number);

    int length = cc_length(cc_number);
    check_cc_type(cc_number, length);

    return 0;
}

// Check the length of the credit card number and return the number of digits.
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

// Check if the credit card number is valid using the Luhn algorithm.
// The algorithm doubles every second digit from the right, subtracts 9 if the result is greater than 9,
// and sums all the digits. If the total modulo 10 is 0, the number is valid.
bool check_cc_validity(long int cc_number)
{
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

// Check the type of the credit card based on its number and length.
// Returns 0 if the card is AMEX, MASTERCARD, or VISA, otherwise returns 1.
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
    return 1;
}