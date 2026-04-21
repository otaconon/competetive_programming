class Solution:
  def threeSumClosest(self, nums: list[int], target: int) -> int:
    nums = sorted(nums)
    n = len(nums)
    closest = 1e9
    ans = 0
    for i in range(n-2):
      l, r = i+1, n-1
      while l < r:
        x = nums[l] + nums[r] + nums[i]
        if abs(target - x) < abs(closest):
          closest = target - x
          ans = x
          
        if nums[l] + nums[r] + nums[i] < target:
          l += 1
        else:
          r -= 1

    return ans