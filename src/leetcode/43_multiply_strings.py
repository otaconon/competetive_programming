class Solution:
  def multiply(self, num1: str, num2: str) -> str:
    n, m = len(num1), len(num2)
    num1, num2 = num1[::-1], num2[::-1]
    answer = [0] * (n + m)
    for i in range(0, n):
      for j in range(0, m):
        product = int(num1[i]) * int(num2[j])
        answer[i+j] += product
        for k in range(i+j+1, n+m):
          if answer[k-1] < 10:
            break
          answer[k] += answer[k-1] // 10
          answer[k-1] %= 10
    return str(int("".join(map(str, reversed(answer)))))
      