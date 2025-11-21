#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
    x = x & 1;
  }

  vector<int> cnt_even(k), cnt_odd(k);
  for (int i = 0; i < n; i++) {
    if (a[i])
      cnt_odd[i % k]++;
    else
      cnt_even[i % k]++;
  }

  int changes = 0;
  int odd_groups = 0;
  vector<int> cost_diff(k);

  for (int i = 0; i < k; i++) {
    if (cnt_odd[i] < cnt_even[i]) {
      changes += cnt_odd[i];
      cost_diff[i] = cnt_even[i] - cnt_odd[i];
    } else {
      changes += cnt_even[i];
      odd_groups++;
      cost_diff[i] = cnt_odd[i] - cnt_even[i];
    }
  }

  if (odd_groups % 2 == 1) {
    int min_cost = INT_MAX;
    for (int i = 0; i < k; i++) {
      min_cost = min(min_cost, cost_diff[i]);
    }
    changes += min_cost;
  }

  cout << changes << '\n';
  return 0;
}