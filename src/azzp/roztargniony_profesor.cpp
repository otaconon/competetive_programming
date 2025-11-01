#include <bits/stdc++.h>

using namespace std;

void solve(int rem, vector<int>& cur, vector<vector<int>>& res) {
  if (rem == 0) {
    res.push_back(cur);
    return;
  }
  if (rem >= 1) {
    cur.push_back(1);
    solve(rem-1, cur, res);
    cur.pop_back();
  }
  if (rem >= 2) {
    cur.push_back(2);
    solve(rem-2, cur, res);
    cur.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<vector<int>> res;
  vector<int> cur;
  solve(n, cur, res);

  //sort(res.begin(), res.end());
  cout << res.size() << '\n';
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }
}