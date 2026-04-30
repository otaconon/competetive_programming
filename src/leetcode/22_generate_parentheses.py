class Solution_0:
  def generateParenthesis(self, n: int) -> list[str]:
    answer = []

    def comb(remaining_closing, cnt: list[int]):
      current_slot_idx = len(cnt)

      if current_slot_idx == n:
        if remaining_closing == 0:
          new_comb = []
          for closing_cnt in cnt:
            new_comb.append('(')
            new_comb.extend([')'] * closing_cnt)
          answer.append("".join(new_comb))
        return

      current_sum_so_far = sum(cnt)
      max_allowed_in_this_slot = (current_slot_idx + 1) - current_sum_so_far

      for i in range(min(remaining_closing, max_allowed_in_this_slot) + 1):
        cnt.append(i)
        comb(remaining_closing - i, cnt)
        cnt.pop()

    comb(n, [])
    return answer
  
class Solution:
  def generateParenthesis(self, n: int) -> list[str]:
    answer = []
    def backtrack(comb, opening, closing):
      nonlocal answer
      if opening + closing == n:
        if opening == closing:
          answer += comb
        return
      
      backtrack(comb + '(', opening+1, closing)
      backtrack(comb + ')', opening, closing-1)
      
    return answer


