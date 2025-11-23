"""
Iterate over i 0 to n-1, which will be the size of substring from beginning
that we consider. then iterate j from 0 to i and check what new plaindromes can be made
with s[i]. then if we decide to split at s[k] the lest number of cuts is going to be
dp[k] + 1
"""


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
    pass

sol = Solution()
print(sol.brute_force(input()))