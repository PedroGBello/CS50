#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int numbers[], int length);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./01_bubble_sort <numbers separated by spaces>\n");
        return 1;
    }
    // Missing error handling for non-integer inputs
    int arr[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    // An alternative to sizeof(arr) / sizeof(arr[0])
    const int LENGTH = argc - 1;;

    bubble_sort(arr, LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        printf("%i ", arr[i]);
    }

    printf("\n");
}

void bubble_sort(int numbers[], int length)
{
    // swap flag
    int swapped;
    do
    {
        swapped = 0; // reset the swapped flag
        // Looping through an array of unordered numbers
        for (int i = 0; i < length - 1; i++)
        {
            // check if the current number is greater than the next number
            if (numbers[i] > numbers[i + 1])
            {
                // swap the numbers
                int bigger = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = bigger;
                swapped = 1; // set the swapped flag
            }
        }
        // Repeat until no swaps are made
    } while (swapped);
}