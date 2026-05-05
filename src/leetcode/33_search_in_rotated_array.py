import bisect

class Solution:
  def search(self, nums: list[int], target: int) -> int:
    n = len(nums)
    if nums[0] <= nums[-1]:
      idx = bisect.bisect_left(nums, target)
      return idx if idx < n and nums[idx] == target else -1
    
    l, r = -1, n
    while l+1 < r:
      m = (l + r) // 2
      if nums[m] >= nums[0]:
        l = m
      else:
        r = m
    
    k = r
    l, r = -1, n
    while l+1 < r:
      m = (l + r) // 2
      if nums[(m + k) % n] < target:
        l = m
      else:
        r = m
    
    idx = (r+k) % n
    return idx if idx < n and nums[idx] == target else -1

