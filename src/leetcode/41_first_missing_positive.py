class Solution:
  def firstMissingPositive(self, nums: list[int]) -> int:
    n = len(nums)
    found_one = False
    for i in range(n):
      if nums[i] == 1:
        found_one = True
        
      if nums[i] > n or nums[i] <= 0:
        nums[i] = 1
        
    if not found_one:
      return 1
    
    for x in nums:
      y = abs(x)-1
      nums[y] = -nums[y] if nums[y] > 0 else nums[y]
    
    for i in range(n):
      if nums[i] > 0:
        return i+1
      
    return n+1
  

sol = Solution()
sol.firstMissingPositive([3,4,-1,1])