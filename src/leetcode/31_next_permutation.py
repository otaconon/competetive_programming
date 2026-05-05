import bisect

class Solution:
  def nextPermutation(self, nums: list[int]) -> None:
    n = len(nums)
    idx = n-1
    while idx-1 >= 0 and nums[idx-1] >= nums[idx]:
      idx-=1
    if idx == 0:
      nums.sort()
      return
    
    current_break = idx-1 
    
    next_break = n-1
    while nums[next_break] <= nums[current_break]:
        next_break-=1
        
    nums[current_break], nums[next_break] = nums[next_break], nums[current_break]
    nums[current_break+1:] = sorted(nums[current_break+1:])
    return nums
    
      