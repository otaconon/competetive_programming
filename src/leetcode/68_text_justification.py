import pprint

class Solution:
  def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
    n = len(words)
    
    ans = [] 
    width = 0
    line = []
    for i in range(n):
      m = len(words[i])
      k = len(line)
      if width + m + k > maxWidth:
        gap_width = 0
        gap_rem = 0
        if k-1:
          gap_width = (maxWidth-width) // (k-1)
          gap_rem = (maxWidth-width) % (k-1)
        ans.append("")
           
        for j in range(k):
          ans[-1] += line[j] 
          if j != k-1:
            ans[-1] += (' ' * gap_width)
          if gap_rem > 0:
            ans[-1] += ' '
            gap_rem -= 1
        if k == 1:
          ans[-1] += ' ' * (maxWidth - len(ans[-1]))
        width = 0
        line = []
      line.append(words[i])
      width += m
    
    if len(line):
      ans.append("")
    for i in range(len(line)):
      ans[-1] += line[i]
      if i != len(line)-1:
        ans[-1] += ' '
      if i == len(line)-1:
        ans[-1] += ' ' * (maxWidth - len(ans[-1]))
    return ans

sol = Solution() 
#pprint.pp(sol.fullJustify(["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20))
pprint.pp(sol.fullJustify(words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16))
