# Two Sets (CSES)

### Problem Statement

We are given a number $n$ and we are supposed to find two such sets $a$ and $b$ that $\sum_{i=1}^{n} a_i = \sum_{i=1}^n b_i $ where $a, b <= n$ and $a_i \ne a_j$ and $b_i \ne b_j$.

### Solution

If $\sum_{i=1}^{n} i$ is odd, then there doesn't exist a solution.

If $\sum_{i=1}^{n} i$ is even, then iterating from the end add numbers to the first set so that $$\sum_{i=1}^{n} i$
