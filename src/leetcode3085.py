class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        n = len(word)
        f = [0]*26
        for c in word:
            f[ord(c) - ord('a')] += 1
        f.sort() 
        ans = 10**9 
        prev = 0
        for i in range(len(f)):
            cnt = 0
            for j in range(i+1,len(f)):
                x, y = f[i], f[j]
                if y - x > k:
                    cnt += y - x - k 
            ans = min(ans, cnt + prev) 
            prev += x
        return ans

    
sol = Solution()
sol.minimumDeletions("aabcaba", 0)