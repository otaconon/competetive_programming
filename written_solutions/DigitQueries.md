# Digit Queries (CSES)

## Problem Statement
Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
Output
For each query, print the corresponding digit.

## Solution

To solve this problem we first have to find how many digits the number at
position $k$ has. To do that we will calculate powers of $10$. Then we can easily
check between which powers of $10$ number $k$ is.

Next we will perform binary search on the range of our powers of $10$. The
key here is the formula for the start of number at position $k$. For a given number $i$ we can check at which position it starts by substracting the previous power of $10$ from it and then multiplying the result by the number of digits and we also need to add previous number position.