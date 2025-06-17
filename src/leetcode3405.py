import math

class Solution:
    def binpow(self, x, y, mod) -> int:
        res = 1
        while y > 0:
            if y & 1:
                res = (res * x) % mod
            x = (x * x) % mod
            y //= 2
        return int(res)
    
    def comb(self, n, k, mod) -> int:
        nn, kk = 1, 1
        for i in range(k):
            nn = (nn * (n-i)) % mod
            kk = (kk * (i+1)) % mod
            
        return int(nn * self.binpow(kk, int(mod-2), mod)) % mod
    
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        mod = 10**9+7
        return ((self.comb(n-1, k, mod) * m) % mod * self.binpow(m-1, n-k-1, mod)) % mod
    
sol = Solution()
print(sol.comb(6, 3, 1e9+7))
print(sol.binpow(3, 4, 1e9+7))
print(sol.countGoodArrays(4, 2, 2))