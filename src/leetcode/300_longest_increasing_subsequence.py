from bisect import bisect_left

class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
    seq = [nums[0]]
    for x in nums:
      if seq[-1] < x:
        seq.append(x)
      else:
        seq[bisect_left(seq, x)] = x
        
    return len(seq) 