#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
public:
  void scramble(string s) {
    for (int i = 0; i < s.size(); i++) {
      string a = s.substr(0, i);
      string b = s.substr(i, s.size()-i);
      scramble(a)
    }
  }

  bool isScramble(string s1, string s2) {
  }
};

int main() {
}