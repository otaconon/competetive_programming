class Solution:
  def countAndSay(self, n: int) -> str:
    if n == 1:
      return '1'
    
    def rle(s: str) -> str:
      cnt, val = 1, 'x'
      new_s = ""
      for c in s:
        if c == val:
          cnt += 1
        else:
          new_s += f"{cnt}{val}"
          cnt = 1
          val = c
      return new_s

    return rle(self.countAndSay(n-1))