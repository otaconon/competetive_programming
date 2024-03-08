#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> a;

void solve() {
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int ans = 0;

    int pnt = 0;
    for (int i = 0; i < a.size(); i++) {
      while (a[i] - a[pnt] >= n) {
        pnt++;
      }
      ans = max(ans, i - pnt + 1);
    } 
    

    cout << max(1, ans) << '\n';
  }

}

int main() {
  solve();
}