from typing import List

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        return [i for i in range(len(nums)) if key in nums[max(0, i-k):min(len(nums), i+k+1)]]