#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];

    for (int dist = 1; dist < n; dist++) {
        for (int left = 0; left < n; left++) {
            if (left + dist < n)
                dp[left][left+dist] = max(dp[left][left] - dp[left+1][left+dist], dp[left+dist][left+dist] - dp[left][left+dist-1]);
        }
    }

    cout << (sum + dp[0][n-1]) / 2 << endl;
}