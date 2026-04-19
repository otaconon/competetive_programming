from collections import Counter

class Solution:
  def threeSum(self, nums: list[int]) -> list[list[int]]:
    cnt = Counter(nums)
    nums = list(set(nums))
    n = len(nums)
    ans = set()
    for i in range(n):
      cnt[nums[i]] -= 1
      for j in range(i, n):
        cnt[nums[j]] -= 1
        x = -nums[i] - nums[j]
        if cnt[nums[i]] >= 0 and cnt[nums[j]] >= 0 and cnt[x] > 0:
          ans.add(tuple(sorted((nums[i], nums[j], x))))
        cnt[nums[j]] += 1
      cnt[nums[i]] += 1

    return list(ans)
        