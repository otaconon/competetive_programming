from collections import defaultdict
import math

class Solution:
  def maxPoints(self, points: list[list[int]]) -> int:
    n = len(points)
    if n <= 2:
      return n

    d = [defaultdict(int) for _ in range(n)]
    for i, (x1, y1) in enumerate(points):
      for j, (x2, y2) in enumerate(points):
        if j <= i:
          continue

        dx = x2 - x1
        dy = y2 - y1
        d[i][dy/dx if dx != 0 else math.inf] += 1
    return max(max(x.values(), default=0) for x in d) + 1


sol = Solution()
sol.maxPoints([[4,5],[4,-1],[4,0]])
