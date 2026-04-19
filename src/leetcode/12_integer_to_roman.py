class Solution:
    def intToRoman(self, num: int) -> str:
      s = str(num)
      n = len(s)
      roman = ['x', 'M', 'D', 'C', 'L', 'X', 'V', 'I']
      ans = []
      for i in range(n):
        j = 2*(i + (4 - n))
        x = int(s[i])
        if 1 <= x <= 3:
          ans.append(roman[j + 1] * (x % 5))
        elif 5 <= x <= 8:
          ans.append(roman[j] + roman[j + (x // 5)] * (x % 5))
        elif x > 0:
          ans.append(roman[j + 1] + roman[j - (x // 5)])
      return "".join(ans)