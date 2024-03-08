import math

n = int(input())

fact = 1
for i in range(1, n+1):
    fact *= i
    print(f"{i}: {fact}")

print(f"{n}: {fact}")