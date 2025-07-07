#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main() {
  cin >> n;
  a.resize(n);

  vector<int> dis(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dis[a[i]-1] = i - (a[i] - 1);
  }

  int ans = 1;

  for (int i = 1; i < n; i++) {
    if(dis[i] < dis[i-1]) {
      ans++;
    }
  }

  cout << ans << '\n';

}