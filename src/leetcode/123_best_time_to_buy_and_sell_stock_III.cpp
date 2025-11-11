#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int ans = 0;
      vector<int> sl(n, 1e9);
      vector<int> sell(n, -1e9);
      for (int i = 1; i < n; i++) {
        sl[i] = min(prices[i-1], sl[i-1]);
        sell[i] = max(sell[i-1], prices[i] - sl[i]);
        ans = max(ans, sell[i]);
      }
      
      vector<int> lr(n, -1);
      for (int i = n-2; i >= 1; i--) {
        lr[i] = max(prices[i+1], lr[i+1]);
        ans = max(ans, max(sell[i-1], 0) + max(lr[i] - prices[i], 0));
      }

      return ans;
    }
};

int main() {
  Solution sol;
  vector<int> prices = {3,3,5,0,0,3,1,4};
  sol.maxProfit(prices);
}