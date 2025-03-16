# Week 03 | Task 02: "Plurality"

## Overview

This project involves implementing a program in C, named `plurality.c`, that simulates a plurality vote election. The program allows voters to cast votes for candidates and determines the winner based on who has the most votes.

### Introduction

The goal of this program is to prompt the user for a list of candidates and the number of voters, then allow each voter to cast a vote for one of the candidates. The program will then tally the votes and print the name of the candidate with the most votes. If there is a tie, the program will print the names of all candidates who have the highest number of votes.

### Functionality

The `vote` function updates the vote count for a candidate if the candidate's name matches the input. The `print_winner` function determines and prints the candidate(s) with the highest number of votes.

### Error Handling

The program includes error handling to ensure that the user inputs a valid number of candidates and voters. If the user enters an invalid candidate name, the program will print "Invalid vote." and continue to prompt for votes.

### Example Output

```console
$ ./plurality Alice Bob Charlie
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Charlie
Alice
Bob
Charlie
```

This example demonstrates a tie between three candidates, each receiving one vote.

## Resources

-   [CS50 Week 03 Lecture](https://cs50.harvard.edu/x/2025/weeks/3/)
-   [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
-   [IBM i C and C++](https://www.ibm.com/docs/en/i/7.5?topic=languages-c-c)
