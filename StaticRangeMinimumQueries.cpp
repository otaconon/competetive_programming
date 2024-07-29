#include <bits/stdc++.h>

using namespace std;

constexpr int LOG = 25;

int log2_floor(int num) {
    return num ? __builtin_clzll(1) - __builtin_clzll(num) : -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(LOG+1));
    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i];
    }
    for (int l = 1; l <= LOG; l++) {
        for (int i = 0; i + (1 << l) <= n; i++) {
            dp[i][l] = min(dp[i][l-1], dp[i + (1 << (l-1))][l-1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int k = log2_floor(r - l + 1);
        cout << min(dp[l][k], dp[r - (1 << k) + 1][k]) << endl;
    }
}