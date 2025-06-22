from typing import List

class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        s = s + fill*(-len(s) % k)
        return [s[k*i:k*(i+1)] for i in range(len(s)//k)]