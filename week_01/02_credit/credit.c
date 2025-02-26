#include <stdio.h>

int cc_length(long int cc_number);

int main(void)
{
    // Luhn's algorithm.
    // Prompt user for credit card number (without spaces or dashes).
    long int cc_number;
    
    printf("Enter credit card number: ");
    scanf("%ld", &cc_number);
    int length = cc_length(cc_number);
    printf("Length: %d\n", length);
    // Check if the credit card number is valid.
    // If valid, print the type of credit card.
    // If invalid, print "INVALID".
    // American Express: 15 digits, starts with 34 or 37.
    // MasterCard: 16 digits, starts with 51, 52, 53, 54, or 55.
    // Visa: 13 or 16 digits, starts with 4. 
    // Otherwise, print "INVALID".

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