#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> red;
vector<int> blue;
void dfs(int node, bool color) {
    if (visited[node]) return;
    visited[node] = true;

    if (!color) {
        red.push_back(node);
    }
    else {
        blue.push_back(node);
    }
    for (auto &neigh: adj[node]) {
        dfs(neigh, color == 0 ? 1 : 0);
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, false);

    long long ans = 0;
    for (auto &node : red) {
        ans += blue.size() - adj[node].size();
    }

    cout << ans << '\n';
}