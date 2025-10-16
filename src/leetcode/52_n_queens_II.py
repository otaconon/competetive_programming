from copy import deepcopy
import pprint

class Solution:
  
  def check(self, r, c) -> bool:
    for (a, b) in self.track:
      if r == a or c == b:
        return False
      if r + c == a + b or r - c == a - b:
        return False
    return True
  
  def placeQueen(self, r, c):
    if self.check(r, c):
      self.track.append((r, c))
      if r == self.n-1:
        self.ans.append(deepcopy(self.track))
      
      for col in range(self.n):
        self.placeQueen(r+1, col)
      self.track.pop()

  
  def generate_answers(self):
    board = [['.' for _ in range(self.n)] for _ in range(self.n)]
    for i in range(len(self.ans)):
      res = deepcopy(board)
      for (r, c) in self.ans[i]:
        res[r][c] = 'Q'
      self.ans[i] = ["".join(res[r]) for r in range(len(res))]

  def solveNQueens(self, n: int) -> list[list[str]]:
    self.n = n
    self.ans = []
    self.track = []
    
    for c in range(self.n):
      self.placeQueen(0, c)
      
    self.generate_answers() 
    
    return len(self.ans)

sol = Solution()  
pprint.pp(sol.solveNQueens(4))