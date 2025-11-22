import math

n = int(input())

ans = 0
a = []
mx = 0
for i in range(n):
  x = input()
  a.append(int(x))
  mx = max(mx, a[-1])

fib = [0, 1]
while fib[-1] < mx:
  fib.append(fib[-1] + fib[-2])


print(ans)