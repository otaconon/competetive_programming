#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }

  bool start_0 = false;
  while (!s.empty()) {
    vector<int> to_delete;

    for (auto it = s.begin(); it != s.end(); it++) {
      if (it == s.begin()) {
        if (!start_0)
          it++;
      }
      else {
        it++;
      }
      
      if (it != s.end()) {
        to_delete.push_back(*it);
        start_0 = false;
      }
      else {
        start_0 = true;
        break;
      }
    }

    for (auto val : to_delete) {
      cout << val << ' ';
      s.erase(val);
    }
  }
  
}

int main() {
  cin >> n;
  solve();
}