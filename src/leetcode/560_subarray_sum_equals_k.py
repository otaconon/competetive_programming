from collections import defaultdict

class Solution:
  def subarraySum(self, nums: list[int], k: int) -> int:
    n = len(nums)
    answer = 0
    pref = [0] * (n+1)
    for i in range(n):
      pref[i+1] = pref[i] + nums[i]
    cnt = defaultdict(int)
    for x in pref:
      answer += cnt[x-k]
      cnt[x] += 1
    
    return answer 