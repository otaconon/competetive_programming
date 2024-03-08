# Nested Ranges Check (CSES)

### Problem Statement

Given n ranges in form [l, r], user is supposed to find for every range whether it contains any other range, and whether it is conatined withing any other ranges.

### Solution

To solve it user has to sort the ranges by left value, and if a.left == b.left, then sort by which right value is greater.

To solve the first sub problem, user can iterate over ranges, keeping track of the greatest right value. Given that the ranges are sorted, it is guaranteed that if $\text{range}_i <= \text{maxEnd}$ the range is contained withing some other range.

To solve the second sub problem, user can iterate over ranges, keeping track of the smallest right value. given that the ranges are sorted, it is guaranteed that if we iterate from the end $\text{range}_i >= \text{minEnd}$ the range contains some other range.
