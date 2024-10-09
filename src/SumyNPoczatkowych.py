from enum import Enum

N = 1000001
is_prime = [True] * N
is_prime[0] = is_prime[1] = False
i = 0
while i * i < N:
    if is_prime[i]:
        for j in range(i * i, N, i):
            is_prime[j] = False
    i += 1

def suma(n):
    ans = 0
    for i in range(n): 
        s = sum([int(d) for d in str(i)])
            
        if is_prime[s]:
            ans += i
            
    print(ans)
    
n = input()
suma(int(n))