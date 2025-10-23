import bisect

'''
class Solution:
  def largestRectangleArea(self, heights: list[int]) -> int:
    n = len(heights) 
    max_h = max(heights)
    m = [[] for _ in range(max_h+1)]
    for (i, height) in enumerate(heights):
      m[height].append(i+1)
    
    coords = [i for i in range(n+2)] 
    max_rect = 0
    for h in sorted(list(set(heights)), reverse=True):
      for x in m[h]:
        coord_idx = bisect.bisect_left(coords, x)
        rect = h
        rect += h * (x - coords[coord_idx-1] - 1)
        rect += h * (coords[coord_idx+1] - x - 1) 
        max_rect = max(max_rect, rect)
        if coords:
          coords.pop(coord_idx)
        
    return max_rect
''' 

class Solution:
  def largestRectangleArea(self, heights: list[int]) -> int:
    n = len(heights) 
    st = [-1] 
    max_rect = 0
    
    for i in range(n):
      while st[-1] != -1 and heights[i] <= heights[st[-1]]:
        prev = st.pop()
        w = i - st[-1] - 1
        max_rect = max(max_rect, w * heights[prev])
      st.append(i)
      
    while st[-1] != -1:
      prev = st.pop()
      w = n - st[-1] - 1
      max_rect = max(max_rect, w * heights[prev])
        
    return max_rect

sol = Solution() 
print(sol.largestRectangleArea(heights = [2,1,5,6,2,3]))
print(sol.largestRectangleArea(heights = [1,1]))
print(sol.largestRectangleArea(heights = [567,789]))
      
