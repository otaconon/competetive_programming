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
    dp = [[math.inf for _ in range(n+1)] for _ in range(n+1)]
    dp[0][0] = -1
    for i in range(1, n+1):
      for j in range(i-1, -1, -1):
        dp[i][j] = dp[i][j+1]
        if s[j:i] == s[j:i][::-1]:
          dp[i][j] = min(dp[i][j], dp[j][0] + 1)
        
    return dp[n][0]

sol = Solution()
s = input()
print(sol.brute_force(s))
print(sol.minCut(s))