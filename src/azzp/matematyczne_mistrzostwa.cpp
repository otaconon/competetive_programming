#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  n = 1 << n;

  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), greater<long long>());

  long long max_fame = -2e18;
  long long sum = 0;
  int next_power_of_2 = 1;
  for (int i = 0; i < n; i++) {
    sum += a[i];

    if ((i + 1) == next_power_of_2) {
      if (sum > max_fame) {
        max_fame = sum;
      }
      next_power_of_2 *= 2;
    }
  }

  cout << max_fame << "\n";

  return 0;
}