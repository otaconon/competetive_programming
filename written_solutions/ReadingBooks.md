# Reading Books (CSES)

### Problem statement

Given an array of times to read a book, print how long it will take at least to read all books by two people, assuming they cannot be reading the same book at once.

### Solution

The solution is quite simple, it is sufficient to just order the books and then $\text{solution} =  max(\sum_{i=1}^{i=n} t_i, max(t_0, ..., t_n) \times 2)$. This approach will work because we can see that if $\sum_{i=1}^{i=n} t_i \le max(t_0, ..., t_n))$ then the first person can read all books other then the longest one so that when the second person finish the long book he can start reading it immediately. In the other case the first person can't finish all the books before the second person finishes the long book, and so after first person doesnt have to waste time waiting for second person to finish.
