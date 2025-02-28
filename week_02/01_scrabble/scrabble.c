#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int scrabble(char *word);

int main(void)
{
    // No puedo declarar un array vacío.
    char *input_1;
    char *input_2;

    printf("Player 1: ");
    scanf("%s", &input_1);

    printf("Player 2: ");
    scanf("%s", &input_2);

    // Check who's got more points.
    int player1_score = scrabble(input_1);
    int player2_score = scrabble(input_2);

    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int scrabble(char *word)
{
    int score = 0;
    int char_index;
    const int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                            1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isalpha(word[i]) == false)
            continue;
        // if lower, turn to upper.
        char_index = toupper(word[i]);

        // if upper, substract 65 to match index positions in points[26].
        char_index -= 65;

        // Add points to score.
        score += points[char_index];
    }
    return score;
}
