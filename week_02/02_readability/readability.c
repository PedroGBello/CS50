#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void coleman_liau_index(char *text);
int count_sentences(char *text);
int count_words(char *text);
int count_letters(char *text);

int main(void)
{
    // No puedo declarar un array vacío.
    char *text;
    do
    {
        printf("Text: ");
        scanf("%[^\n]", &text);
    }
    while (!strlen(text));

    coleman_liau_index(text);
}

void coleman_liau_index(char *text)
{
    int sentences = count_sentences(text);
    int words = count_words(text);
    int letters = count_letters(text);
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_sentences(char *text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if ((text[i]) == '.' || (text[i]) == '!' || (text[i]) == '?')
            count++;
    }
    return count;
}

int count_words(char *text)
{
    // Sentences will contain at least one word.
    int count = 0;
    int length = strlen(text);
    bool in_word = false;
    for (int i = 0; i < length; i++)
    {
        // If char is NOT a space, enter word and add one to count.
        if (!isspace(text[i]))
        {
            if (!in_word)
            {
                in_word = true;
                count++;
            }
        }
        // If char IS a space, exit word.
        else
        {
            in_word = false;
        }
    }
    printf("Number of words: %i\n", count);
    return count;
}

int count_letters(char *text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
            count++;
    }
    return count;
}
