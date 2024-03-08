# Sum Of Four Values (CSES)

### Problem statement

We are given a list $a$ of numbers and a number $x$. We are supposed to find four distinct indexes so that $a_i + a_j + a_k + a_c = x$.

### $N^2\log{(N^2)}$ solution

For this solution we create a vector of all possible pairs of numbers. Then iterate over every pair and using binary search try to find such pair that they sum up to $x$.

### $N^2$ solution

For this solution we have to make an observation that we can add pairs to a container after we have iterated over them. So we iterate over all numbers pairs and for every pair of two numbers we have iterated over we add it to an unordered_map. Then for a pair of numbers we are currently iterating we check if there is such pair in map so that two pairs add up to $x$.
