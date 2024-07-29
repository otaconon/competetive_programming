#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<vector<int>> a;
vector<vector<int>> dp;

void dfs(int node, int parent) {
    dp[0][node] = 0;
    dp[1][node] = -INT_MAX;

    for (int child : a[node]) {
        if (child == parent) {
            continue;
        }
        dfs(child, node);
        dp[0][node] += max(dp[0][child], dp[1][child]);
        int opt = min(dp[0][child] - dp[1][child], 0);
        dp[1][node] = max(dp[1][node], opt);
    }

    dp[1][node] += dp[0][node] + 1;
}
 
int main() {
    cin >> n;
    a.resize(n+1);
    dp.resize(2, vector<int>(n+1));
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    dfs(1, -1);
 
    cout << max(dp[0][1], dp[1][1]) << endl;
}
