class Solution:
  def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
    res = []
    candidates.sort()
    n = len(candidates)
    
    def take_next(comb, idx):
      total = sum(comb)
      
      if total == target:
        res.append(comb[:])
        return
      elif total > target:
        return

      for i in range(idx+1, n):
        comb.append(candidates[i])
        take_next(comb, i)
        comb.pop()

    take_next([], -1)
    return res

