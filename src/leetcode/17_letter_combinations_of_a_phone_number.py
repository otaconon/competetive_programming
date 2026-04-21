from itertools import product

class Solution:
  def letterCombinations(self, digits: str) -> list[str]:
    sets = ['x', 'x', "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    return ["".join(prod) for prod in product(*(sets[int(x)] for x in digits))]