#include <ctype.h>
#include <stdio.h>

void print_pyramid(const int height);
int get_height(void);

int main(void)
{
    const int height = get_height();
    print_pyramid(height);
    return 0;
}

// Prompt user for a height between 1 and 8
int get_height(void)
{
    int height;
    do
    {
        printf("Please enter an integer between 1 and 8: ");
        scanf("%d", &height);
    }
    // Check if the height is between 1 and 8 inclusive
    // ! Missing integer validation (e.g. if the user enters a character)
    while (height < 1 || height > 8);

    return height;
}

// Print a row of bricks
void print_rows(const int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}

// Print spaces
void print_spaces(const int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

// Print a pyramid
void print_pyramid(const int height)
{
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - i - 1);
        print_rows(i + 1);
        printf("  ");
        print_rows(i + 1);
        printf("\n");
    }
}