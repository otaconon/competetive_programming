# Josephus Problem (CSES)

### Problem statement

People are sitting in a circle, the task is to say if every kth person is removed from the cricle in what order are they going to be removed.

### Solution

Start with a order set from gnu pbds of all people. Next iterate over them using .find_by_order(i). The idea is to after every iteration save i+k+1 -circle.size() value, so that on the next iteration we can start from the value % circle.size(). after each iteration delete
