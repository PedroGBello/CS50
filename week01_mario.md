# Week 01: Mario

## Table of Contents

-   [Overview](#overview)
-   [Objectives](#objectives)
-   [Requirements](#requirements)
-   [Instructions](#instructions)
-   [Submission](#submission)
-   [Resources](#resources)

## Overview

<!-- Provide a brief description of the Mario project for CS50 Week 01. -->

Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks. In a file called `mario.c`, implement a program in C that recreates that pyramid, using hashes (`#`) for bricks, as in the below:

```
   #  #
  ##  ##
 ###  ###
####  ####
```

And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive `int` between, say, 1 and 8, inclusive.
Here’s how the program might work if the user inputs `8` when prompted:

```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

```

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

## Objectives

-   Understand the basics of loops and conditionals in C.
-   Implement a simple program using these concepts.

## Requirements

-   In a file called `mario.c`, implement a program in C that prints a pyramid, using hashes (`#`) for bricks.,
-   The pyramid should be right-aligned.

## Instructions

1. Prompt the user for the height of the pyramid.
   1.1. If the user doesn't input a positive integer between 1 and 8, inclusive, the program should re-prompt the user until he/she cooperates.
   1.2. Make sure the program doesn't allow characters.
2. Use loops to print the pyramid with the specified height.
3. Ensure the pyramid is right-aligned.

## Resources

-   [CS50 Week 01 Lecture](https://cs50.harvard.edu/x/2025/weeks/1/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
