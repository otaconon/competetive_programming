from bisect import bisect_left

class Solution:
  def threeSum(self, nums: list[int]) -> list[list[int]]:
    nums = sorted(nums)
    n = len(nums)
    ans = []
    for i in range(n-2):
      if i > 0 and nums[i] == nums[i-1]:
        continue
      
      l, r = i+1, n-1
      while l < r:
        if nums[l] + nums[r] + nums[i] == 0:
          ans.append((nums[i], nums[l], nums[r]))
          while l < r and nums[l] == nums[l+1]:
            l += 1
          while l < r and nums[r] == nums[r-1]:
            r -= 1
          
          l += 1
          r -= 1
          
        elif nums[l] + nums[r] + nums[i] < 0:
          l += 1
        else:
          r -= 1

    return list(ans)
        