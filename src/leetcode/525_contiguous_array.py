class Solution:
  def findMaxLength(self, nums: list[int]) -> int:
    n = len(nums)
    seen = {0: -1}
    answer = 0
    sum_so_far = 0
    for i in range(n):
      sum_so_far += nums[i]
      x = 2 * sum_so_far - i - 1
      if x in seen:
        answer = max(answer, i - seen[x])
      if x not in seen:
        seen[x] = i
    return answer
    