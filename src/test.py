from collections import Counter

n = int(input())
a = [int(input()) for _ in range(n)]

max_sum = max(a) * 2 if n > 1 else max(a)
fibs = set()
f1, f2 = 0, 1
fibs.add(f1)
fibs.add(f2)
while f2 <= max_sum:
  f1, f2 = f2, f1 + f2
  fibs.add(f2)

count_a = Counter(a)
result = 0

for fib in fibs:
  for val in count_a:
    complement = fib - val
    if complement in count_a:
      if complement == val:
        result += count_a[val] * (count_a[val] - 1) // 2
      elif complement > val:
        result += count_a[val] * count_a[complement]

print(result)
