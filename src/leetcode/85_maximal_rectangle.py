import pprint

'''
class Solution:
  def maximalRectangle(self, matrix: list[list[str]]) -> int:
    n, m = len(matrix), len(matrix[0])
    matrix = [list(map(int, row))for row in matrix]
    col = [[0 for _ in range(m)] for _ in range(n)]
    row = [[0 for _ in range(m)] for _ in range(n)]
    for r in range(0, n):
      for c in range(0, m):
        if not matrix[r][c]:
          continue
        col[r][c] = matrix[r][c]
        row[r][c] = matrix[r][c]
        if r > 0:
          col[r][c] += col[r-1][c]
        if c > 0:
          row[r][c] += row[r][c-1]
    
    ans = 0 
    for R in range(0, n):
      for C in range(0, m):
        if not matrix[R][C]:
          continue
        
        r, c = R, C
        cnt_r, cnt_c = row[r][c], col[r][c]
        ans = max(ans, cnt_r, cnt_c)
        x = 1
        while r > 0 and c > 0 and cnt_r >= x+1 and cnt_c >= x+1 and matrix[r-1][c-1]:
          r, c = r-1, c-1
          x += 1
          cnt_r = min(cnt_r, row[r][c]+x-1)
          cnt_c = min(cnt_c, col[r][c]+x-1)
          ans = max(ans, cnt_r*x, cnt_c*x, x*x)

    return ans
'''
  
class Solution:
  def maximalRectangle(self, matrix: list[list[str]]) -> int:
    n, m = len(matrix), len(matrix[0])
    matrix = [list(map(int, row))for row in matrix]
    hist = [0] * m
    ans = 0
    for r in range(n):
      for c in range(m):
        hist[c] = hist[c] + 1 if matrix[r][c] else 0
      ans = max(ans, self.getMaxArea(hist)) 
    
    return ans
    
  def getMaxArea(self, hist):
    m = len(hist)
    left, right = [-1] * m, [m] * m
    st = [] 
    for c in range(m):
      while st and hist[st[-1]] >= hist[c]:
        st.pop()
      left[c] = st[-1] if st else -1
      st.append(c)
    
    st.clear()
    for c in range(m-1, -1, -1):
      while st and hist[st[-1]] >= hist[c]:
        st.pop()
      right[c] = st[-1] if st else m
      st.append(c)
    
    return max((right[i] - left[i] - 1) * hist[i] for i in range(m))

  
sol = Solution()
#pprint.pp([["1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","0","0","0"],["0","1","1","1","1","0","0","0"]])
#print(sol.maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))
#print(sol.maximalRectangle([["1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","0","0","0"],["0","1","1","1","1","0","0","0"]]))
print(sol.maximalRectangle([["0","0","1"],["1","1","1"]]))