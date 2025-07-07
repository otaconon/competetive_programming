#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& output, int u) {
    for (int v : adj[u]) {
        if (!vis[v])
            dfs(adj, vis, output, v);
    }
    output.push_back(u);
}

struct SCC {
    void scc(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& output, int n) {
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(adj, vis, output, i);
        }
        
        vector<vector<int>> adj_rev(n);
        for (int u = 0; u < n; u++) {
            for (int v : adj[u])
                adj_rev[v].push_back(u);
        }

        
    }
};

int main() {

}