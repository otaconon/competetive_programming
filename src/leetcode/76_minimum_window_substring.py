class Solution:
  def minWindow(self, s: str, t: str) -> str:
    n = len(s)
    m = len(t)
    ans = (1000000, "")
    req = {}
    ch = {}
    for c in t:
      if c not in req:
        req[c] = 0
        ch[c] = 0
      req[c] += 1

    tail = 0
    for (i, c) in enumerate(s):
      if c not in req or c not in ch:
        ch[c] = 0
        req[c] = 0
      ch[c] += 1
      complete = True
      for d in req.keys():
        if ch[d] < req[d]:
          complete = False
          break
      if complete:
        while tail < n and ch[s[tail]] > req[s[tail]]:
          ch[s[tail]] -= 1
          tail += 1
        if ans[0] > i-tail+1:
          ans = (i-tail+1, s[tail:i+1])
        
    return ans[1]
  
sol = Solution()
print(sol.minWindow(s = "ADOBECODEBANC", t = "ABC"))
print(sol.minWindow(s = "a", t = "aa"))
print(sol.minWindow(s = "a", t = "a"))
          