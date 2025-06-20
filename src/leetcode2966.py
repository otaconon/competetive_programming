class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums) // 3
        nums.sort()
        x = [nums[i*3:(i+1)*3] for i in range(0, n)]
        for a in x:
            if a[-1] - a[0] > k:
                return []
        return x