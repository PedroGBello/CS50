# Week 04 | Task 01: "Volume"

## Overview

This project involves implementing a program in C, named `volume.c`, that adjusts the volume of an audio file in the WAV format. The program reads an input WAV file, applies a scaling factor to the audio samples, and writes the adjusted audio to an output WAV file.

### Introduction

The goal of this program is to prompt the user for an input WAV file, an output WAV file, and a scaling factor. The program will then read the audio data from the input file, adjust the volume by multiplying each audio sample by the scaling factor, and write the adjusted audio data to the output file.

### Functionality

The `volume` program performs the following steps:

1. **Check Command-Line Arguments**: Ensures that the user provides exactly three command-line arguments: the input file, the output file, and the scaling factor.
2. **Open Files**: Opens the input and output files. If either file cannot be opened, the program prints an error message and exits.
3. **Read Scaling Factor**: Reads the scaling factor from the command-line arguments. The scaling factor can be a positive or negative floating-point number, where a negative value results in phase inversion.
4. **Copy Header**: Copies the 44-byte header from the input file to the output file, preserving the metadata about the WAV file.
5. **Adjust Volume**: Reads each audio sample from the input file, multiplies it by the scaling factor, and writes the adjusted sample to the output file.
6. **Close Files**: Closes the input and output files.

### Error Handling

The program includes error handling to ensure that the user provides valid command-line arguments and that the input and output files can be opened. If any errors occur, the program prints an appropriate error message and exits.

### Example Output

```console
$ ./volume coldplay_trouble.wav modified_trouble.wav 0.5
```

This example demonstrates how to half the volume of the audio in `coldplay_trouble.wav` and save the adjusted audio to `modified_trouble.wav`.

```console
$ ./volume coldplay_trouble.mp3 modified_trouble.mp3 2.0
Not a WAVE file.
```

This example demonstrates how the program detects a non-WAVE file and terminates with an error message.

## Resources

-   [CS50 Week 04 Lecture](https://cs50.harvard.edu/x/2025/weeks/4/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
