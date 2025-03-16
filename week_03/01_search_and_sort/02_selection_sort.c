#include <stdio.h>
#include <stdlib.h>

int min_index = 0;

void selection_sort(int arr[], int length);
int find_min(int arr[], int length, int start_index);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./02_selection_sort <numbers separated by spaces>\n");
        return 1;
    }
    // Missing error handling for non-integer inputs
    int arr[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    // An alternative to sizeof(arr) / sizeof(arr[0])
    const int LENGTH = argc - 1;

    selection_sort(arr, LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    return 0;
}

void selection_sort(int arr[], int length)
{
    // Repeat the process for the remaining elements
    for (int i = 0; i < length - 1; i++)
    {
        // find minimum unsorted element in the array
        int min_value = find_min(arr, length, i);

        // swap it with the first unsorted element in the array
        if (arr[i] != min_value)
        {
            int temp = arr[i];
            arr[i] = min_value;
            arr[min_index] = temp;
        }
    }
}

int find_min(int arr[], int length, int start_index)
{
    int min_value = arr[start_index];

    for (int i = start_index; i < length; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
            min_index = i;
        }
    }
    return min_value;
}
