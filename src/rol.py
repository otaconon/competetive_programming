n, k = input().split()
n, k = int(n), int(k)
a = input().split()
b = []

for i in range(len(a)):
    b.append(a[(i + k) % n])
    
for i in b:
    print(i, end=' ')