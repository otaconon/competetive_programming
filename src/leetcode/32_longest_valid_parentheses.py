class Solution:
  def longestValidParentheses(self, s: str) -> int:
    st = []
    dp = [0] * len(s)
    for (idx, c) in enumerate(s):
      if len(st) == 0:
        if c == '(':
          st.append(idx)
        continue
      
      if c == ')':
        top_idx = st.pop()
        dp[idx] = dp[top_idx-1] + dp[idx-1] + 2
      elif c == '(':
        st.append(idx)
    
    return max(dp)
  
sol = Solution()
print(sol.longestValidParentheses(")(((((()())()()))()(()))("))