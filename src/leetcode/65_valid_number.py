import re

class Solution:
  def isNumber(self, s: str) -> bool:
    number = r"(\+|-)?[0-9]+"
    pattern = r"({}(\.[0-9]*)?|(\+|-)?\.[0-9]+)((e|E){})?".format(number, number, number)
    x = re.search(pattern, s)
    #print(x)
    
    if x and len(x.group()) == len(s):
      return True 
    
    return False
  
sol = Solution()

assert(sol.isNumber("0089"), True)
assert(sol.isNumber("2e10"), True)
assert(sol.isNumber("-90E3"), True)
assert(sol.isNumber("-123.456e789"), True)
assert(sol.isNumber("-.456e789"), True)
assert(sol.isNumber("-.e789"), False)