#include "bits/stdc++.h"

using namespace std;

/*
class Solution {
public:
  unordered_map<string, bool> mp;

  bool isScramble(string s1, string s2) {
    int n = s1.size();

    if (s2.size() != n)
      return false;

    if (s1 == s2)
      return true;

    if (n == 1)
      return false;

    string key = s1 + " " + s2;

    if (mp.find(key) != mp.end())
      return mp[key];

    for (int i = 1; i < n; i++) {
      bool withoutswap = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)));

      if (withoutswap)
        return true;

      bool withswap = (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)));

      if (withswap)
        return true;
    }

    return mp[key] = false;
  }
};


class Solution {
public:
  bool isScramble(string s1, string s2) {
    int n = s1.size();
    vector<vector<vector<string>>> comb(n, vector<vector<string>>(n));
    for (int i = 0; i < n; i++)
      comb[0][i].emplace_back(1, s2[i]);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        for (auto &x : comb[i - 1][j]) {
          comb[i][j].push_back(x + s2[j + i]);
          comb[i][j].push_back(s2[j + i] + x);
        }
      }
    }

    for (auto &x : comb[n - 1][0]) {
      if (x == s1)
        return true;
    }

    return false;
  }
};
*/


class Solution {
public:
  unordered_map<string, bool> vis;

public:
  bool isScramble(string s1, string s2) {
    int n = s1.size();
    if (s1 == s2)
      return true;
    if (n == 1) 
      return false;

    auto key = s1 + ' ' + s2;
    if (vis.contains(key))
      return vis[key];

    for (int i = 1; i < n; i++) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
        return true;

      if (isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i)))
        return true;
    }

    return vis[key] = false;
  }
};

int main() {
  Solution sol;
  // sol.isScramble("great", "rgeat");
  sol.isScramble("abcde", "caebd");
  sol.isScramble("abc", "bca");
}