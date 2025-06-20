from typing import List

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        nums.sort()
        mn = nums[0]
        for i in range(1, n):
            if nums[i] - mn > k:
                mn = nums[i]
                ans += 1
        return ans

sol = Solution()
print(sol.partitionArray([3,6,1,2,5], 2))
                