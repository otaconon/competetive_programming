#include <bits/stdc++.h>

using namespace std;

template<typename T>
void print_vec2(vector<vector<T>>& vec) {
  for (auto i = 0; i < vec.size(); i++) {
    for (auto j = 0; j < vec[i].size(); j++) {
      print("{} ", vec[i][j]);
    }
    println();
  }
}

namespace top_down {
class Solution {
public:
  int n, m;
  string s, p;
  vector<int> is_star;
  map<pair<int, int>, bool> cache;

  void dfs(int i, int j) {
    auto ij = make_pair(i, j);
    if (cache.contains(ij)) {
    }
    else if (i >= n && j >= m) {
      cache[ij] = true;
    }
    else if (j >= m) {
      cache[ij] = false;
    }
    else if (is_star[j]) {
      bool match = i < n && (s[i] == p[j] || p[j] == '.');
      if (match) {
        dfs(i+1, j);
      }

      dfs(i, j+1);
      cache[ij] = cache[make_pair(i, j+1)] || (match && cache[make_pair(i+1, j)]);
    }
    else if (p[j] != '.' && s[i] != p[j]) {
      cache[ij] = false;
    }
    else if (i < n) {
      dfs(i+1, j+1);
      cache[ij] = cache[make_pair(i+1, j+1)];
    }
    else {
      cache[ij] = false;
    }
  }

  bool isMatch(string s, string p) {
    n = s.size();
    this->s = s;

    string new_p = "";
    for (auto c : p) {
      if (c == '*') {
        is_star.back() = true;
      }
      else {
        new_p += c;
        is_star.push_back(false);
      }
    }
    p = new_p;

    this->p = p;
    this->m = p.size();

    dfs(0, 0);
    return cache[make_pair(0, 0)];
  }
};
}

namespace bottom_up {
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    s = " " + s;
    p = " " + p;

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
      dp[0][j] = p[j] == '*' ? dp[0][j-2] : false;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j] == '*') {
          dp[i][j] = (s[i] == p[j-1] || p[j-1] == '.') ? dp[i-1][j-1] || dp[i-1][j] : false;
          dp[i][j] = dp[i][j-2] || dp[i][j];
        }
        dp[i][j] = (p[j] == '.' || s[i] == p[j]) ? dp[i-1][j-1] : dp[i][j];
      }
    }

    //print_vec2(dp);
    return dp[n][m];
  }
};
}

int main() {
  bottom_up::Solution sol;
  std::cout << sol.isMatch("aaa", ".*") << '\n';
}
