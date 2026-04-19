class Solution:
  def longestCommonPrefix(self, strs: list[str]) -> str:
    ans = ""
    for i in range(min(len(s) for s in strs)):
      if all(s[:i] == strs[0][:i] for s in strs):
        ans = strs[0][:i]
    return ans
        
