#include <bits/stdc++.h>

using namespace std;

struct edge {
    int v;
    long long w;
    bool next;
};

vector<vector<edge>> adj;
vector<bool> vis;
vector<long long> ans;
void dfs(int node) {
    if (vis[node])
        return;
    
    vis[node] = true;

    for (auto [child, w, next] : adj[node]) {
        if (next) {
            ans[child] = ans[node] + w;
        }
        else {
            ans[child] = ans[node] - w;
        }
        
        dfs(child);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    for (int i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({(int)v, w, true});
        adj[v].push_back({(int)u, w, false});
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}