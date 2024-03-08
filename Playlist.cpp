#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  set<int> uni;

  int ans = 1;
  int l = 0, r = 0;

  uni.insert(a[l]);

  while(r < n-1) {
    r++;
    while (uni.count(a[r])) {
      uni.erase(a[l]);
      l++;
    }
    uni.insert(a[r]);

    ans = max(ans, (int)uni.size());
  }

  cout << ans << '\n';

}