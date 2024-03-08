# Collecting Numbers II (CSES)

### Problem statement

We are given a list of integers, we iterate over them and select numbers in ascending order. That means for every iteration from i = 0 to i = n, we are allowed to take a number $a_j$ only if every integer $a_i > 0$ and $a_i<a_j$ has already been collected. We are supposed to say how many iterations it takes to collect all numbers.

### Solution

n collecting number we first create an array pos, that stores information about what value is at what position

Next we iterate over the pos array and check whether the pos[i] > pos[i+1], if it is then that means a value i+1 that is supposed to be after value i  is before it. So we have to increase our rounds counter by one.

Next what we have to check for every query, are values of pos[l]
