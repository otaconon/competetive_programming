#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll mod = 998244353;

int main() {
    int q, k;
    cin >> q >> k;
    vector<ll> dp(k+1);
    dp[0] = 1;
    while(q--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            for (int i = k; i >= x; i--) {
                dp[i] = (dp[i] + dp[i-x]) % mod;
            }
        }
        else {
            for (int i = x; i <= k; i++) {
                dp[i] = (dp[i] - dp[i-x] + mod) % mod;
            }
        }
        
        cout << dp[k] << endl;
    }    
}