# Week 01: Credit

## Overview

This program prompts the user for a credit card number and then reports (via `printf`) whether it is a valid American Express, MasterCard, or Visa card number, according to the definitions of each’s format.

_Key Features:_

**Prompt for Input**: The program prompts the user to enter a credit card number without spaces or dashes.

**Luhn's Algorithm**: It checks the validity of the credit card number using Luhn's algorithm as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit.
2. Add those products' digits together.
3. Add the sum to the sum of the digits that weren’t multiplied by 2.
4. If the total’s last digit is 0, the number is valid!

**Card Type Identification**: Based on the length and starting digits, it identifies the card type:

1. American Express uses 15-digit numbers, starting with 34 or 37.
2. MasterCard uses 16-digit numbers, starting with 51-55.
3. Visa uses 13- and 16-digit numbers, starting with 4.

Output: It prints `AMEX`, `MASTERCARD`, `VISA`, or `INVALID` based on the card type and validity. [Click here for testing.](https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards)

## Resources

-   [CS50 Week 01 Lecture](https://cs50.harvard.edu/x/2025/weeks/1/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
