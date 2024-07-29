#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a;

vector<long long> dp;
void dfs(int node, int parent) {
    dp[node] = 1;
    for (int child : a[node]) {
        if (node != parent) {
            dfs(child, node);
            dp[node] += dp[child];
        }
    }
}

int main() {
    cin >> n;
    a.resize(n+1);
    dp.resize(n+1);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        a[u].push_back(i);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << dp[i]-1 << ' ';
    }
}