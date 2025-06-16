class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans = -1
        mn = 1e9+5
        for i in range(len(nums)):
            ans = max(ans, nums[i] - mn)
            mn = min(mn, nums[i])
        return -1 if ans <= 0 else ans