class Solution:
  def findSubstring(self, s: str, words: list[str]) -> list[int]:
    n = len(s)
    m = len(words)
    k = len(words[0])
    d = {}
    for frag in words:
      if frag not in d:
        d[frag] = 0
      d[frag] += 1
  
    ans = []
    for i in range(0, k):
      frags = {}
      q = []
      for j in range(i, n, k):
        if j+k > n:
          break
        
        frag = s[j:j+k]
        if frag in d:
          if frag not in frags:
            frags[frag] = 0
              
          frags[frag] += 1
          q.append(frag)
          while frags[frag] > d[frag]:
            frags[q.pop(0)] -= 1
            
          if frags == d:
            ans.append(j-k*(m-1))
              
        else:
          frags = {}
          q = [] 

    return ans
        
sol = Solution()
print(sol.findSubstring("barfoofoobarthefoobarman", 
                ["bar","foo","the"]))