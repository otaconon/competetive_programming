class Solution:
  def isValidSudoku(self, board: list[list[str]]) -> bool:
    rows, cols, squares = [set() for _ in range(9)], [set() for _ in range(9)], [[set() for _ in range(3)] for _ in range(3)]
    for r in range(9):
      for c in range(9):
        if board[r][c] == '.':
          continue
        if board[r][c] in rows[r] | cols[c] | squares[r//3][c//3]:
          return False
        rows[r].add(board[r][c])
        cols[c].add(board[r][c])
        squares[r//3][c//3].add(board[r][c])
    return True