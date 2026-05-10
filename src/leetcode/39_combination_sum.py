class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    res = []

    def solve(i, k, ds):
      if i == len(candidates):
        if k == 0:
          res.append(list(ds))
        return
      if candidates[i] <= k:
        ds.append(candidates[i])
        solve(i, k - candidates[i], ds)
        ds.pop()
      solve(i+1, k, ds)

    solve(0, target, [])
    return res
