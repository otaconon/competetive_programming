'''
class Solution:
  def trap(self, height: list[int]) -> int:
    n = len(height)
    ans = 0
    
    max_right = [0] * n
    max_left = [0] * n
    for i in range(1, n):
      max_left[i] = max(max_left[i-1], height[i-1])
    for i in range(n-2, 0, -1):
      max_right[i] = max(max_right[i+1], height[i+1])
      
    for i in range(n):
      ans += max(0, min(max_left[i], max_right[i]) - height[i])
        
    return ans
''' 
class Solution:
  def trap(self, height: list[int]) -> int:
    n = len(height)
    ans = 0
    
    left = 0
    right = n-1 
    max_left = height[left]
    max_right = height[right]
    
    while left < right:
      if max_left < max_right:
        left += 1
        max_left = max(height[left], max_left)
        ans += max_left - height[left]
      else:
        right -= 1
        max_right = max(height[right], max_right)
        ans += max_right - height[right]
      
    return ans 
    
sol = Solution()
print(sol.trap([0,1,0,2,1,0,1,3,2,1,2,1]))
print(sol.trap([4,2,0,3,2,5]))
print(sol.trap([4, 2, 3]))
