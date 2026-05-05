class Solution:
  def divide(self, dividend: int, divisor: int) -> int:
    sgn = -1 if (dividend < 0) ^ (divisor < 0) else 1
    dividend, divisor = abs(dividend), abs(divisor)
    
    if dividend < divisor:
      return 0
    
    q, r = 0, 0
    for i in range(dividend.bit_length()):
      r = (r << 1) + (dividend >> (dividend.bit_length()-i-1))
      q = q << 1
      if r >= divisor:
        r -= divisor
        q += 1
    return q * sgn
        
