import sys

sys.set_int_max_str_digits(5000005)

def solve():
  MOD1 = 10**9 + 7
  MOD2 = 10**9 + 9

  LOG_PHI = 0.20898764024997873
  OFFSET = 0.3494850021680094

  input_data = sys.stdin.read().split()
  if not input_data:
    return

  iterator = iter(input_data)
  N = int(next(iterator))

  counts = {}
  distinct_lengths = set()
  for _ in range(N):
    s = next(iterator)
    length = len(s)
    distinct_lengths.add(length)

    val = int(s)
    h1 = val % MOD1
    h2 = val % MOD2

    key = (length, h1, h2)
    counts[key] = counts.get(key, 0) + 1

  sorted_lengths = sorted(list(distinct_lengths))
  intervals = []
  for L in sorted_lengths:
    k_start = int((L - 1 + OFFSET) / LOG_PHI) - 2
    if k_start < 3:
      k_start = 3

    k_end = int((L + 1 + OFFSET) / LOG_PHI) + 3

    intervals.append((k_start, k_end))

  if not intervals:
    print(0)
    return

  intervals.sort()
  merged = []
  
  curr_start, curr_end = intervals[0]
  for i in range(1, len(intervals)):
    next_start, next_end = intervals[i]
    if next_start <= curr_end + 100:
      curr_end = max(curr_end, next_end)
    else:
      merged.append((curr_start, curr_end))
      curr_start, curr_end = next_start, next_end
  merged.append((curr_start, curr_end))

  fibs_by_len = {}
  def multiply_matrices(M1, M2, mod):
    return (
        (M1[0]*M2[0] + M1[1]*M2[2]) % mod,
        (M1[0]*M2[1] + M1[1]*M2[3]) % mod,
        (M1[2]*M2[0] + M1[3]*M2[2]) % mod,
        (M1[2]*M2[1] + M1[3]*M2[3]) % mod
    )

  def power_matrix(M, p, mod):
    res = (1, 0, 0, 1)
    base = M
    while p > 0:
      if p % 2 == 1:
        res = multiply_matrices(res, base, mod)
      base = multiply_matrices(base, base, mod)
      p //= 2
    return res

  def get_fib_pair(n, mod):
    if n == 0:
      return 0, 1
    M = (1, 1, 1, 0)
    res = power_matrix(M, n, mod)
    return res[1], res[0]

  for start, end in merged:
    curr_f1, next_f1 = get_fib_pair(start, MOD1)
    curr_f2, next_f2 = get_fib_pair(start, MOD2)

    for k in range(start, end + 1):
      f_len = int(k * LOG_PHI - OFFSET) + 1

      if f_len in distinct_lengths or (f_len - 1) in distinct_lengths:
        if f_len not in fibs_by_len:
          fibs_by_len[f_len] = []
        fibs_by_len[f_len].append((curr_f1, curr_f2))

      new_f1 = (curr_f1 + next_f1) % MOD1
      curr_f1, next_f1 = next_f1, new_f1

      new_f2 = (curr_f2 + next_f2) % MOD2
      curr_f2, next_f2 = next_f2, new_f2

  total_count = 0
  for (u_len, u_h1, u_h2), count_u in counts.items():
    candidate_fibs = []
    if u_len in fibs_by_len:
      candidate_fibs.extend(fibs_by_len[u_len])
    if (u_len + 1) in fibs_by_len:
      candidate_fibs.extend(fibs_by_len[u_len + 1])

    for (f_h1, f_h2) in candidate_fibs:
      target_h1 = (f_h1 - u_h1)
      if target_h1 < 0:
        target_h1 += MOD1

      target_h2 = (f_h2 - u_h2)
      if target_h2 < 0:
        target_h2 += MOD2

      key_a = (u_len, target_h1, target_h2)
      if key_a in counts:
        count_v = counts[key_a]
        if key_a == (u_len, u_h1, u_h2):
          total_count += count_u * (count_v - 1)
        else:
          total_count += count_u * count_v

      key_b = (u_len + 1, target_h1, target_h2)
      if key_b in counts:
        count_v = counts[key_b]
        total_count += count_u * count_v

      if u_len > 1:
        key_c = (u_len - 1, target_h1, target_h2)
        if key_c in counts:
          count_v = counts[key_c]
          total_count += count_u * count_v

  print(total_count // 2)


if __name__ == '__main__':
  solve()
