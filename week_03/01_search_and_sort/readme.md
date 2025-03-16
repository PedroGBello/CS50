# Week 03 | Task 01: "Search and Sort"

## Overview

This project involves implementing two programs in C, named `01_bubble_sort.c` and `02_selection_sort.c`, that demonstrate different sorting algorithms: Bubble Sort and Selection Sort. These programs take a list of integers as command-line arguments and sort them in ascending order.

### Introduction

The goal of these programs is to sort a list of integers provided by the user via command-line arguments. Each program uses a different sorting algorithm to achieve this goal.

### Functionality

#### Bubble Sort

The `bubble_sort` function is the core of the `01_bubble_sort.c` program. It takes an array of integers and its length as arguments and sorts the array in ascending order using the Bubble Sort algorithm.

#### Selection Sort

The `selection_sort` function is the core of the `02_selection_sort.c` program. It takes an array of integers and its length as arguments and sorts the array in ascending order using the Selection Sort algorithm.

### Error Handling

Both programs NOT YET include error handling to ensure that the user provides valid input. If the user does not provide any integers as command-line arguments, the programs will print a usage message and exit.

### Example Output

These examples demonstrate the sorted output of the provided integers using Bubble Sort and Selection Sort algorithms, respectively.

```console
$ ./01_bubble_sort 9 6 3 0 7 4 1 8 5 2
0 1 2 3 4 5 6 7 8 9
```

```console
$ ./02_selection_sort 9 6 3 0 7 4 1 8 5 2
0 1 2 3 4 5 6 7 8 9
```

## Resources

-   [CS50 Week 03 Lecture](https://cs50.harvard.edu/x/2025/weeks/3/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
