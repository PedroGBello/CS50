# Week 04 | Task 03: "Recover"

## Overview

This project involves implementing a program in C, named `recover.c`, that recovers JPEG images from a forensic image. The program reads a forensic image, identifies the beginning of JPEG files, and writes each JPEG to a separate file.

> [!NOTE]
> There's a `card.raw` file provided by the CS50's staff to test this program.

### Introduction

The goal of this program is to prompt the user for a forensic image file, read through the file to identify JPEG headers, and recover the JPEG images by writing them to separate files.

### Functionality

The `recover` program performs the following steps:

1. **Check Command-Line Arguments**: Ensures that the user provides exactly one command-line argument: the name of the forensic image file.
2. **Open Forensic Image**: Opens the forensic image file. If the file cannot be opened, the program prints an error message and exits.
3. **Read Data Blocks**: Reads the forensic image file in blocks of 512 bytes.
4. **Identify JPEG Headers**: Checks each block for the JPEG header signature.
5. **Write JPEG Files**: When a new JPEG header is found, the program starts writing to a new JPEG file. If a JPEG file is already open, it closes the current file before opening a new one.
6. **Close Files**: Closes all open files and frees allocated memory.

### Error Handling

The program includes error handling to ensure that the user provides a valid command-line argument and that the forensic image file can be opened. If any errors occur, the program prints an appropriate error message and exits.

### Example Output

```console
$ ./recover card.raw
```

This example demonstrates how to recover JPEG images from the forensic image file `card.raw`.

## Resources

-   [CS50 Week 04 Lecture](https://cs50.harvard.edu/x/2025/weeks/4/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
