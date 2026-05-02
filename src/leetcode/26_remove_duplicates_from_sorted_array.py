class Solution:
  def removeDuplicates(self, nums: list[int]) -> int:
    idx, prev = 0, -1000
    for x in nums:
      if x != prev:
        nums[idx] = x
        idx += 1
      prev = x
    return idx
      