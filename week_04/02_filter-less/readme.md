# Week 04 | Task 02: "Filter (Less Comfortable)"

## Overview

This project involves implementing a program in C, named `filter.c`, that applies various filters to a BMP image. The program reads an input BMP file, applies the specified filter, and writes the modified image to an output BMP file.

> [!NOTE]
> For this problem, I extended the functionality of code provided by CS50’s staff, working on the four functions in `helpers.c`.

### Introduction

The goal of this program is to prompt the user for an input BMP file, an output BMP file, and a filter flag. The program will then read the image data from the input file, apply the specified filter, and write the modified image data to the output file.

### Functionality

The `filter` program performs the following steps:

1. **Check Command-Line Arguments**: Ensures that the user provides exactly three command-line arguments: the filter flag, the input file, and the output file.
2. **Open Files**: Opens the input and output files. If either file cannot be opened, the program prints an error message and exits.
3. **Read Headers**: Reads the BMP file headers from the input file to ensure it is a valid 24-bit uncompressed BMP 4.0 file.
4. **Read Image Data**: Reads the pixel data from the input file into memory.
5. **Apply Filter**: Applies the specified filter to the image data. The available filters are:
    - `-b`: Blur
    - `-g`: Grayscale
    - `-r`: Reflect
    - `-s`: Sepia
6. **Write Image Data**: Writes the modified pixel data to the output file.
7. **Close Files**: Closes the input and output files.

### Error Handling

The program includes error handling to ensure that the user provides valid command-line arguments and that the input and output files can be opened. If any errors occur, the program prints an appropriate error message and exits.

### Example Output

```console
$ ./filter -g images/tower.bmp tower_grayscale.bmp
$ ./filter -s images/yard.bmp yard_sepia.bmp
$ ./filter -r images/courtyard.bmp courtyard_sepia.bmp
$ ./filter -b images/stadium.bmp stadium_blur.bmp
```

This example demonstrates how to apply various filters to different BMP images and save the modified images.

## Resources

-   [CS50 Week 04 Lecture](https://cs50.harvard.edu/x/2025/weeks/4/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
