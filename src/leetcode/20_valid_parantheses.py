class Solution:
  def isValid(self, s: str) -> bool:
    stack = []
    par = {'(': ')', '[': ']', '{': '}'}
    for c in s:
      if len(stack) == 0 or c in ['(', '[', '{']:
        stack.append(c)
      elif par[stack[-1]] == c:
        stack.pop()
      else:
        return False
    return len(stack) == 0