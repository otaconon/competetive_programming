#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long s, k, n;
  cin >> s >> k >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());

  long long ans = 0; 
  for (int i = 0; i < min(n, s); i++) {
    ans = max(ans, (i+1)*a[i] - k*(i+1));
  }

  cout << ans << '\n';
}