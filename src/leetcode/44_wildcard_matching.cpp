#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    int ki = -1, kj = -1;
    while (i < s.size()) {
      if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
        i++; j++;
      }
      else if (j < p.size() && p[j] == '*') {
        ki = i; kj = j;
        j++;
      }
      else if (ki != -1) {
        i = ++ki; j = kj+1;
      }
      else {
        return false;
      }
    }
    
    while (p[j] == '*' && j < p.size()) j++;
    return j == p.size();
  }
};

int main() {
  Solution sol;
  println("{}", sol.isMatch("aa", "a"));
}