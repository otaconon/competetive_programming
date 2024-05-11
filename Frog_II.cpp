#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, 1e9+7);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j < n)
                dp[i+j] = min(dp[i+j], dp[i] + abs(a[i+j] - a[i]));
        }
    }

    cout << dp[n-1] << endl;
}