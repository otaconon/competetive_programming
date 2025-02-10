#include <bits/stdc++.h>

using namespace std;

/*
    For the first and second subtask, the problem can be solved in O(n^2)
    Simply perform dfs from eaach node counting the reachable nodes
*/

int dfs12(vector<vector<int>>& adj, vector<bool>& vis, int node) {
    if (vis[node])
        return 0;
    
    vis[node] = true;

    int cnt = 1;
    for (auto& x : adj[node]) {
        cnt += dfs12(adj, vis, x);
    }

    return cnt;
}

void dfs3(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& output, int node) {
    vis[node] = true;

    for (auto& x : adj[node]) {
        if (!vis[x])
            dfs3(adj, vis, output, x);
    }
    output.push_back(node);
}

void subtask12() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
    }

    vector<bool> vis(n);
    for (int node = 0; node < n; node++) {
        cout << dfs12(adj, vis, node)-1 << endl;
        vis.assign(n, 0);
    }
}

void dfs_cond(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& cnt, vector<int>& roots, int node, vector<int>& res) {
    vis[node] = true;

    res[node] = cnt[roots[node]];
    for (auto v : adj[roots[node]]) {
        if (!vis[v]) {
            dfs_cond(adj, vis, cnt, roots, v, res);
        }
        res[node] += res[v];
    }
}

void scc() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> adj_rev(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj_rev[v].push_back(u);
    }

    vector<bool> vis(n);
    vector<int> order(n);

    for (int node = 0; node < n; node++) {
        if (!vis[node])
            dfs3(adj, vis, order, node);
    }

    vis.assign(n, false);
    reverse(order.begin(), order.end());
    vector<int> roots(n);

    vector<vector<int>> components;
    for (auto v : order) {
        if (!vis[v]) {
            vector<int> component;
            dfs3(adj_rev, vis, component, v);
            components.push_back(component);
            int root = *min_element(component.begin(), component.end());
            for (auto u : component) {
                roots[u] = root;
            }
        }
    }

    vector<vector<int>> adj_cond(n);
    for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
            if (roots[v] != roots[u]) {
                adj_cond[roots[v]].push_back(roots[u]);
            }
        }
    }

    vector<int> cnt(n);
    for (int v = 0; v < n; v++) {
        cnt[roots[v]]++;
    }

    // vector<int> leafs;
    // for (int v = 0; v < n; v++) {
    //     if (adj_cond[roots[v]].size() == 0) {
    //         leafs.push_back(roots[v]);
    //     }
    // }
    
    vis.assign(n, false);
    vector<int> res(n);
    for (int v = 0; v < n; v++) {
        if (!vis[v])
            dfs_cond(adj_cond, vis, cnt, roots, v, res);
    }

    for (int v = 0; v < n; v++) {
        cout << res[v]-1 << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        string x = argv[1];
        if (x == "brute")
            subtask12();
        else if (x == "scc")
            scc();
    }
    else {
        scc();
    }
}