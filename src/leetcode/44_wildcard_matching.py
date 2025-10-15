class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    s = " " + s
    p = " " + p
    n = len(s)
    m = len(p)
    
    dp = [[False for _ in range(m)] for _ in range(n)]
    dp[0][0] = True
    for j in range(1, m):
      if p[j] != '*':
        break
      dp[0][j] = True
    
    for i in range(1, n):
      for j in range(1, m):
        if p[j] == '?' or p[j] == s[i]:
          dp[i][j] = dp[i-1][j-1]
        elif p[j] == '*':
          dp[i][j] = dp[i-1][j-1] or dp[i][j-1] or dp[i-1][j]
          
    return dp[n-1][m-1]
  

sol = Solution()
assert(sol.isMatch("adceb", "*a*b") == True)
assert(sol.isMatch("aa", "aa") == True)
assert(sol.isMatch("aab", "c*a*b") == False)
assert(sol.isMatch("miss", "m??*s") == True)
assert(sol.isMatch("mississippi", "m??*ss*?i*pi") == False)
assert(sol.isMatch("abcabczzzde", "*abc???de*") == True)
assert(sol.isMatch("ab", "*?*?*") == True)
assert(sol.isMatch("", "*") == True)
assert(sol.isMatch("", "a") == False)
assert(sol.isMatch("a", "") == False)