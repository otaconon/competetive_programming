class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    n = len(s)
    m = len(p)
    
    if n == 0:
      for c in p:
        if c != '*':
          return False
      return True
    elif m == 0:
      return False
    
    matched = [False for _ in range(m)]
    dp = [[False for _ in range(m)] for _ in range(n)]
    dp[0][0] = (p[0] == '?') or (s[0] == p[0])
    for i in range(n):
      dp[i][0] = dp[i][0] or p[0] == '*'
      matched[0] = matched[0] or dp[i][0]
    for j in range(1, m):
      if p[j-1] != '*':
        break
      dp[0][j] = p[j] == '?' or p[j] == s[0]
      matched[j] = matched[j] or dp[0][j]
    
    for i in range(1, n):
      match_cnt = int(matched[0])
      for j in range(1, m):
        if p[j] == s[i] or p[j] == '?':
          dp[i][j] = dp[i-1][j-1] or (dp[i][j-1] and p[j-1] == '*')
        elif p[j] == '*' and match_cnt == j:
          dp[i][j] = True
        
        matched[j] = matched[j] or dp[i][j]
        match_cnt += int(matched[j])
    
    for j in range(m-1, -1, -1):
      if dp[-1][j]:
        return True
      elif p[j] != '*':
        return False
      
    return False
  

sol = Solution()
print(sol.isMatch("adceb", "*a*b"))
print(sol.isMatch("aa", "aa"))
print(sol.isMatch("aab", "c*a*b"))
print(sol.isMatch("miss", "m??*s"))
print(sol.isMatch("mississippi", "m??*ss*?i*pi"))
print(sol.isMatch("abcabczzzde", "*abc???de*"))
print(sol.isMatch("ab", "*?*?*"))