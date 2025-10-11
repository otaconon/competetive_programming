import pprint


class Solution:

  def solveSudoku(self, board: list[list[str]]) -> None:
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    blocks = [set() for _ in range(9)]
    dyn = [[True] * 9 for _ in range(9)]
    al = set(['1', '2', '3', '4', '5', '6', '7', '8', '9'])

    def get_block(r, c):
      a = r//3
      b = c//3
      return blocks[a*3 + b % 3]

    sr = []
    for r in range(9):
      for c in range(9):
        x = board[r][c]
        if x != '.':
          x = int(x)
          rows[r].add(x)
          cols[c].add(x)
          get_block(r, c).add(x)
        else:
          sr.append((r, c))

    def search(idx) -> bool:
      if idx >= len(sr):
        return True
      
      r, c = sr[idx]
      uni = rows[r].union(cols[c], get_block(r, c))

      found = False 
      for i in range(1, 10):
        if i in uni:
          continue
        
        rows[r].add(i)
        cols[c].add(i)
        get_block(r, c).add(i)
        board[r][c] = str(i)

        if search(idx+1):
          found = True
          break
        
        rows[r].remove(i)
        cols[c].remove(i)
        get_block(r, c).remove(i)
        board[r][c] = '.'
        
      return found
    
    search(0)

    pprint.pp(board)


sol = Solution()
sol.solveSudoku([["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], [
                "4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]])
