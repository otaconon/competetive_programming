# Gray Code (CSES)

### Problem Statement

For given integer $n$ print all possible bit strings $b$ of length $n$ in such way that $b_i$ differs by only one bit from $b_{i+1}$.

### Solution

One has to realize that this problem can be solved by recursion. For $n = 1$ all possible bit strings are "0" and "1" for $n=2:$ "00", "01", "11", "10". If one is careful it is possible to see that the first to bit strings are the same as the ones for $n=1$ but with $ 0$ added at the beginning and the reverse of $n=1$ with $ 1$ added. for $n=3:$ "000", "001", "011", "010", "110", "111", "101", "100". Now it's the same deal as with $n=2$. It should now be obvious how to solve this problem with recursion.
