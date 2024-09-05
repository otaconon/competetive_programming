#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
vector<bool> chosen;
int cnt = 0;
bool dfs(int node, int parent) {
    bool contains_chosen = chosen[node];
    for (auto& child : adj[node]) {
        if (child != parent) {
            if (dfs(child, node)) {
                contains_chosen = true;
            }
        }
    }

    if (!contains_chosen)
        cnt++;
    
    return contains_chosen;
}

int main() {
    int k, n;
    cin >> n >> k;

    vis.resize(n);
    adj.resize(n);
    chosen.resize(n, false);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        chosen[x] = true;
        start = x;
    }

    dfs(start, -1);

    cout << n - cnt << endl;
}