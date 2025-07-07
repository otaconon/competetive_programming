#include "bits/stdc++.h"

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> ans;
  int cnt = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '|') {
      ans.push_back(cnt);
      cnt = 0;
    }
    else {
      cnt++;
    }
  }

  for (auto& x : ans)
    cout << x << ' ';
}