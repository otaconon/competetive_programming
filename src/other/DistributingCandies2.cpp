#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      long long distributeCandies(int n, int limit) {
          long long ans = 0;
          for (int i = 0; i <= min(n, limit); i++) {
              ans += max(min(limit, n-i) - max(0, n-i-limit)+1, 0);
          }
  
          return ans;
      }
  };

int main() {
  
}