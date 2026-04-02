class Solution:
  def smallestRepunitDivByK(self, k: int) -> int:
    r = 0
    seen = set()
    for i in range(10**6):
      r = (10*r % k + 1) % k
      if r in seen:
        return -1
      seen.add(r)
      if r == 0:
        return i+1

    return -2
        
sol = Solution()
k = int(input())
ans = sol.smallestRepunitDivByK(k)
print(ans)