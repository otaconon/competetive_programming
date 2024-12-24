#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("snakes");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX/2));

    int space_used = 0;
    int largest_group = -1;
    for (int i = 1; i <= n; i++) {
        largest_group = max(largest_group, a[i-1]);
        dp[i][0] = largest_group * i;
        for (int j = 1; j <= k; j++) {
            int net = a[i-1];
            for (int m = i-1; m >= 0; m--) {
               dp[i][j] = min(dp[i][j], dp[m][j-1] + (i - m) * net);
               net = max(net, a[m-1]);
            }
        }
        space_used += a[i-1];
    }

    cout << dp[n][k] - space_used << endl;
}