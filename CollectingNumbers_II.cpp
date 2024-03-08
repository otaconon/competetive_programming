#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;
vector<int> pos;

void print_vec(vector<int>& vec) {
  for (int i = 0; i < n; i++) {
    cout << vec[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin >> n >> m;
  a.resize(n+1);
  pos.resize(n+1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    ans += (pos[i] > pos[i+1]);
  }

  set<pair<int, int>> newPairs;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;

    if (a[l]+1 <= n)
      newPairs.insert({a[l], a[l]+1});
    if (a[l]-1 >= 1)
      newPairs.insert({a[l]-1, a[l]});
    if (a[r]+1 <= n)
      newPairs.insert({a[r], a[r]+1});
    if (a[r]-1 >= 1)
      newPairs.insert({a[r]-1, a[r]});

    for (auto swapped : newPairs) {
      ans -= (pos[swapped.first] > pos[swapped.second]);
    }

    swap(a[l], a[r]);
    pos[a[l]] = l;
    pos[a[r]] = r;

    for (auto swapped : newPairs) {
      ans += (pos[swapped.first] > pos[swapped.second]);
    }

    cout << ans << '\n';
    newPairs.clear();
  }
}