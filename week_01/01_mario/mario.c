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

int get_height(void)
{
    int height;
    do
    {
        printf("Please, input an integer between 1 and 8: ");
        scanf("%d", &height);
    }
    // Missing check for non-integer input
    while (height < 1 || height > 8);

    return height;
}

void print_rows(const int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}

void print_spaces(const int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // // Formatted output instead of a loop:
    // printf("%*s", spaces, "");
}

void print_pyramid(const int height)
{
    /*
        The `print_pyramid` function takes an integer `height` as an argument and prints a pyramid pattern of that height to the console, with each level consisting of left-aligned and right-aligned bricks separated by two spaces.
    */
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - i - 1);
        print_rows(i + 1);
        printf("  ");
        print_rows(i + 1);
        printf("\n");
    }
}