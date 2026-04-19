class Solution:
  def romanToInt(self, s: str) -> int:
    roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    n, ans, i = len(s), 0, 0
    while i < n:
      if i < n-1 and roman[s[i]] < roman[s[i+1]]:
        ans += roman[s[i+1]] - roman[s[i]]
        i += 1
      else:
        ans += roman[s[i]]
      i += 1
    return ans

sol = Solution()
sol.romanToInt(input())