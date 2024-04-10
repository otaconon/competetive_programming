# Subarray Distinct Values (CSES)

### Problem statement

Given an array of $n$ integers, your task is to calculate the number of subarrays that have at most $k$ distinct values.

### My Solution

First create a map that is going to count how many values equal to $x$ there are. Next using two pointers find for every left pointer the largest right pointer so that there are no more than k distinct values. When the right pointer reaches such place that there are more than $k$ distinct values, using the combination formula $n(n+1) \over 2$ calculate all possible subarrays, then we also have to take care of overlapping combinations from previous calculations. For that we can keep track of a last right pointer value and from all possible subarrays substract number of all possible subarrays on interval l to lastR.
