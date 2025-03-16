# Week 03 | Task 03: "Runoff"

## Overview

This project involves implementing a program in C, named `runoff.c`, that simulates an instant runoff election. The program allows voters to rank candidates in order of preference and determines the winner through a series of elimination rounds until a candidate has more than 50% of the votes.

### Introduction

The goal of this program is to prompt the user for a list of candidates and the number of voters, then allow each voter to rank the candidates in order of preference. The program will then simulate the runoff process, eliminating the candidate with the fewest votes in each round and redistributing those votes to the next preferred candidate until a winner is determined.

### Functionality

The `vote` function records a voter's preference if the vote is valid. The `tabulate` function counts the votes for non-eliminated candidates. The `print_winner` function checks if any candidate has more than 50% of the votes and prints the winner's name. The `find_min` function finds the candidate with the fewest votes. The `is_tie` function checks if the election is tied between all remaining candidates. The `eliminate` function eliminates the candidate(s) with the fewest votes.

### Error Handling

The program includes error handling to ensure that the user inputs a valid number of candidates and voters. If the user enters an invalid candidate name, the program will print "Invalid vote." and continue to prompt for votes.

### Example Output

```console
$ ./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Alice
```

This example demonstrates an election with three candidates and five voters. Alice wins the election after the runoff process.

## Resources

-   [CS50 Week 03 Lecture](https://cs50.harvard.edu/x/2025/weeks/3/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
