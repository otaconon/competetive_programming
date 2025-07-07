#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("time");

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> cities(n);
    vector<vector<int>> roads(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        roads[u].push_back(v);
    }

    int MAX_T = 1000;
    vector<vector<int>> dp(MAX_T+1, vector<int>(n, -1));
    dp[0][0] = 0;
    int res = 0;
    for (int i = 1; i <= MAX_T; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i-1][j] == -1)
                continue;

            for (auto& neighbor : roads[j]) {
                dp[i][neighbor] = max(dp[i][neighbor], dp[i-1][j] + cities[neighbor]);
            }
        }
        res = max(res, dp[i][0] - i*i * c);
    }

    cout << res << endl;
}