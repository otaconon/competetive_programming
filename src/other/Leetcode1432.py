import math
import copy

class Solution:
    def maxDiff(self, num: int) -> int:
        num = list(str(num))
        mn, mx = math.inf, 0
        for i in range(10):
            for j in range(10):
                t = copy.copy(num)
                for k in range(len(num)):
                    if t[k] == str(i):
                        t[k] = str(j)
                if t[0] == '0':
                    continue
                mn = min(mn, int("".join(t)))
                mx = max(mx, int("".join(t)))
        return mx - mn
    
sol = Solution()
print(sol.maxDiff(123456))
