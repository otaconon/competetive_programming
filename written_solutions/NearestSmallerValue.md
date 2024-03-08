# Nearest Smaller Value (CSES)

### Problem statement

We are given a list of numbers and for every number $a_i$are suposed to find max $j$ such that $a_j < a_i$.

### Solution O(Nlog(N))

First we sort all the values. Next we iterate over them inserting new value to a set that is ordered by value idexes, and performing binary search to find the closest smaller index then the one we are currently at. It is guaranteed that all the indexes are of smaller values because they came before in a sorted vector. The only we need to be wary of is the repeated values. All the same values should be inserted at once, otherwise it is no longer true that all indexes in set are of smaller values.

### Solution O(N)

We have to simply iterate over every number, holding a stack of previously seen numbers. As long as the number we are currently at is smaller than the stack.top() we stack.pop(). After we are done with deleting the stack.top() is the closest index of a smaller number. The observation one has to make for this solution is that if we are at $a_i < a_{i-j}$ then there is no need to hold on to $a_{i-j}$ because $a_i$ is always going to be a closer smaller value to $a_{i+k}$.
