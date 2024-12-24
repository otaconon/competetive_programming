#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto& x : a)
    cin >> x;
  for (auto& x : b)
    cin >> x;

  multimap<int, int> ms;
  for (int i = 0; i < m; i++)
    ms.insert({b[i], i});
  
  int idx = 0;
  vector<int> ans(m, -1);
  for (int i = 0; i < n; i++) {
    set<int> to_delete;
    for (auto it = ms.lower_bound(a[i]); it != ms.end(); it++) {
      to_delete.insert(it->first);
      ans[it->second] = i+1;
    }

    for (auto& y : to_delete) {
      ms.erase(y);
    }
  }

  for (auto& x : ans)
    cout << x << endl;
}