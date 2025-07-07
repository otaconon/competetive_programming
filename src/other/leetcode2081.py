class Solution:
    def base10_to_basek(self, n, k):
        if n == 0:
            return "0"

        digits = "0123456789"
        result = ""

        while n > 0:
            result = digits[n % k] + result
            n //= k

        return result

    def kMirror(self, k: int, n: int) -> int:
        M = 100000
        ans = 0
        
        for sz in range(1, 15):
            start = 10**(sz-1)
            end = 10**sz
            for x in range(start, end):
                a = str(x)
                pal = int(a + a[-2::-1])
                y = self.base10_to_basek(pal, k)
                if y == y[::-1]:
                    ans += pal
                    n -= 1
                if n <= 0:
                    return ans
 
            for x in range(start, end):
                a = str(x)
                pal = int(a + a[::-1])
                y = self.base10_to_basek(pal, k)
                if y == y[::-1]:
                    ans += pal
                    n -= 1
                if n <= 0:
                    return ans
           
        return ans
    
sol = Solution()
print(sol.kMirror(9, 20)) 