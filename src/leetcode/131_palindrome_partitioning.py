class Solution:
  def partition(self, s: str) -> list[list[str]]:
    n = len(s)
    ans = set()
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
        
      if palindromes:
        ans.add(cuts)
    return ans
        