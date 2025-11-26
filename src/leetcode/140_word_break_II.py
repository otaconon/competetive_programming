class Solution:
  def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
    n = len(s)
    word_set = set(wordDict)
    ans = set()
    for i in range(2**n):
      prev = 0
      cuts = []
      for j in range(n):
        if (i >> j) & 1:
          cuts.append(s[prev:j+1])
          prev = j+1
      if prev != n:
        cuts.append(s[prev:n])

      in_word_set = True
      for x in cuts:
        if x not in word_set:
          in_word_set = False
          break

      if in_word_set:
        ans.add(" ".join(cuts))
        
    return list(ans)
