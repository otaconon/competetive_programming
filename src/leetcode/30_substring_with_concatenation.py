class Solution:
  def findSubstring(self, s: str, fragments: list[str]) -> list[int]:
    n = len(s)
    m = len(fragments)
    k = len(fragments[0])
    d = {}
    for frag in fragments:
      if frag not in d:
        d[frag] = 0
      d[frag] += 1
  
    ans = []
    for i in range(0, n):
      cache = {}
      found = True
      for j in range(k, k*m+1, k):
        if i+j > n:
          found = False
          break
        frag = s[i+j-k:i+j]
        if frag not in cache:
            cache[frag] = 0
        cache[frag] += 1
        
      if len(cache.keys()) != len(d.keys()):
        found = False
        
      if not found:
        continue
      
      for (frag, cnt) in cache.items():
        if frag not in d:
          found = False
          break
        if cnt != d[frag]:
          found = False
          break
      
      if found:
        ans.append(i)
    
    return ans
        
sol = Solution()
print(sol.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", 
                ["fooo","barr","wing","ding","wing"]))