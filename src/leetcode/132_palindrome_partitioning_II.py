from collections import defaultdict
from functools import lru_cache
import math

class Solution:
  def brute_force(self, s: str) -> list:
    n = len(s)
    best_cuts = []
    for i in range(2**n):
      prev = 0
      cuts = []
      for j in range(n):
        if (i >> j) & 1:
          cuts.append(s[prev:j+1])
          prev = j+1
      if prev != n:
        cuts.append(s[prev:n]) 
        
      palindromes = True
      for x in cuts:
        if x != x[::-1]:
          palindromes = False
          break
        
      if palindromes and (len(cuts) < len(best_cuts) or len(best_cuts) == 0):
        best_cuts = cuts
        
    return best_cuts
          
  def minCut(self, s: str) -> int:
    n = len(s)
    pal = [[False for _ in range(n)] for _ in range(n)]
    dp = [0 for _ in range(n)]
    for r in range(n):
      mn = r
      for l in range(r+1):
        if s[l] == s[r] and (l+1 > r-1 or pal[l+1][r-1]):
          pal[l][r] = 1
          mn = 0 if l == 0 else min(mn, dp[l-1]+1)
      dp[r] = mn
         
    return dp[n-1]
  
  def okMinCut(self, s: str) -> int:
    n = len(s)
    d = defaultdict(set)
    def comp_palindromes(l, r):
      while l >= 0 and r < n and s[l] == s[r]:
        d[l].add(r)
        l -= 1; r += 1
        
    for i in range(n):
      comp_palindromes(i, i)
      comp_palindromes(i, i+1)
    
    @lru_cache(None)
    def dfs(u):
      if u == n: return 0
      tmp = [] 
      for v in range(u, n+1):
        if v in d[u]: tmp.append(dfs(v+1)+1)
      return min(tmp) 

    return dfs(0)-1

sol = Solution()
s = input()
print(sol.brute_force(s))
print(sol.minCut(s))