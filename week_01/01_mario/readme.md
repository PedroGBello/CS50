# Week 01 | Task 01: "Mario"

## Overview

Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario encounters various obstacles, including pyramids of blocks that he must jump over. This project involves implementing a program in C, named `mario.c`, that recreates these pyramids using hashes (`#`) to represent the bricks.

### Introduction

The goal of this program is to prompt the user for a positive integer between 1 and 8, inclusive, which determines the height of the pyramids. The program will then generate a visual representation of the pyramids with the specified height, ensuring that the pyramids are properly aligned and separated by a gap of two spaces.

### Functionality

The `print_pyramid` function is the core of this program. It takes an integer `height` as an argument and prints a pyramid pattern of that height to the console, with level consisting of left-aligned and right-aligned bricks, separated by two spaces. The width of the gap between the pyramids remains constant, regardless of the height.

### Error Handling

The program includes error handling to ensure that the user inputs a valid height. If the user enters a value outside the range of 1 to 8, the program will repeatedly prompt the user until a valid input is provided. This ensures that the program operates correctly and generates the desired pyramid pattern.

### Example Output

```
   #  #
  ##  ##
 ###  ###
####  ####
```

This example demonstrates a pyramid of height 4, with each level properly aligned and separated by a gap.

## Resources

-   [CS50 Week 01 Lecture](https://cs50.harvard.edu/x/2025/weeks/1/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
