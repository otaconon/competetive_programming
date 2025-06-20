class Solution:
    def get(self, ch):
        if ch == 'N':
            return 0
        elif ch == 'E':
            return 1
        elif ch == 'S':
            return 2
        elif ch == 'W':
            return 3
        
    def maxDistance(self, s: str, k: int) -> int:
        cnt = [0, 0, 0, 0]
        ans = 0
        for ch in s:
            d = self.get(ch)
            cnt[d] += 1
            front = cnt[d]
            back = cnt[(d + 2) % 4]
            right = cnt[(d + 1) % 4]
            left = cnt[(d + 3) % 4]
            ans = max(ans, front + right + min(k, back + left) - max(0, back + left - k)) 
            ans = max(ans, front + left + min(k, back + right) - max(0, back + right - k)) 
            ans = max(ans, back + right + min(k, front + left) - max(0, front + left - k)) 
            ans = max(ans, back + left + min(k, front + right) - max(0, front + right - k)) 
            
        return ans
        
sol = Solution()
sol.maxDistance("NWSE", 1) 