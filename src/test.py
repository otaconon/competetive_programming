mod = 998244353
n = 243
s = ""
prev = 0
for i in range(50):
    s += str(n)
    x = int(s) % mod
    print(x - prev)
    prev = x