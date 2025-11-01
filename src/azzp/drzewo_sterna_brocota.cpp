#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> prev = {{0, 1}, {1, 0}};
  vector<pair<int, int>> cur;
  for (int i = 0; i < n; i++) {
    cur = {};
    cur.push_back(prev[0]);
    for (int j = 1; j < prev.size(); j++) {
      cur.push_back({prev[j-1].first + prev[j].first, prev[j-1].second + prev[j].second});
      cur.push_back(prev[j]);
    }
    prev = cur;
  }

  for (int i = 0; i < cur.size(); i++) {
    cout << cur[i].first << '/' << cur[i].second << ' ';
  }
}