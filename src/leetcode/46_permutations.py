class Solution:
  def permute(self, nums: list[int]) -> list[list[int]]:
    answer = []
    def generate(permutation: list[int], k: int):
      if k == len(nums):
        answer.append(permutation)
        return
      for i in range(len(permutation)):
        generate(permutation[:i] + [nums[k]] + permutation[i:], k+1)
    return answer
        
      
        