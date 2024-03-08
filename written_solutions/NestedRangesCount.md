# Nested Ranges Count (CSES)

### Problem statement

User is supposed to find the amount of times each range is contained within other range, and how many different ranges it contains.

### Solution

To solve this problem one has to use gnu ordered_set, and use its operation order_of_key.

First one has to sort ranges in ascending order.

Next one iterates over them checking how many greater range ends there are using .order_of_key(). This gives us contained[i]

And lastly, iterate in reverse order checking how many smaller range ends there are. This gives us contains[i]
