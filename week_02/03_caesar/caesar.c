#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const int MOD = 26;

int key(int num, int modulus);
bool only_digits(char *text);
char *rotate(int key, char *text);

int main(int argc, char *argv[])
{
    // Input validation:

    if (argc < 2)
    {
        printf("No arguments were provided.\n");
        return 1;
    }
    if (argc > 2)
    {
        printf("Too many arguments provided. Expected 1.\n");
        return 1;
    }
    // If CLA not decimal, print "Usage: ./caesar key" and return 1.
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Program starts:
    int k = key(atoi(argv[1]), MOD);
    char *plaintext; // No puedo declarar un array vacío.

    printf("Plaintext: ");
    scanf("%[^\n]", plaintext);

    char *ciphertext = rotate(k, plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    free(ciphertext);
    return 0;
}

bool only_digits(char *text)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(text[i]))
        {
            continue;
        }
        return false;
    }
    return true;
}

int key(int num, int modulus)
{
    /*
        This function admits positive and negative integers,
        based on periodicity and modular arithmetic.
        Returns a non-negative integer.
    */
    int key = abs(num + modulus) % modulus;
    return key;
}

char *rotate(int key, char *text)
{
    int length = strlen(text);
    char *ciphertext = malloc(length + 1);

    // Encrypt:
    for (int i = 0; i < length; i++)
    {
        // text[i] is original ASCII.
        if (isupper(text[i]))
        {
            ciphertext[i] = upper[(text[i] - 'A' + key) % MOD];
        }
        else if (islower(text[i]))
        {
            ciphertext[i] = lower[(text[i] - 'a' + key) % MOD];
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }
    ciphertext[length] = '\0';
    return ciphertext;
}
