import math

class Solution:
  def getPermutation(self, n: int, k: int) -> str:
    m = 1
    y = 1
    ans = []
    jumps = []
    while y != k:
      f = math.factorial(n-m)
      cnt = 0
      while y+f <= k:
        y += f
        cnt += 1
      jumps.append(cnt)
      m += 1
      
    nums = [str(i) for i in range(1, n+1)]
    for x in jumps:
      ans.append(nums.pop(x))
    for x in nums:
      ans.append(x)
    
    return "".join(ans)
 
class Test:
  ans = ""
  cnt = 0
  k = 0
  
  def permute(self, perm, n):
    if len(perm) >= n:
      self.cnt += 1
      if self.cnt == self.k:
        self.ans = perm
    
    for i in range(1, n+1):
      if str(i) in perm:
        continue
      self.permute(perm + str(i), n)
  
  def getPermutation(self, n: int, k: int) -> str:
    self.ans = ""
    self.cnt = 0
    self.k = k
    self.permute("", n)
    return self.ans 
  
sol = Solution()
test = Test()
assert(sol.getPermutation(3, 3) == test.getPermutation(3, 3))
assert(sol.getPermutation(4, 9) == test.getPermutation(4, 9))
assert(sol.getPermutation(1, 1) == test.getPermutation(1, 1))
assert(sol.getPermutation(9, 136371) == test.getPermutation(9, 136371))
assert(sol.getPermutation(3, 2) == test.getPermutation(3, 2))