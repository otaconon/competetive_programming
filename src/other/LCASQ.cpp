#include <bits/stdc++.h>

using namespace std;

constexpr int LOG = 20;

vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node) {
    for (auto child : tree[node]) {
        depth[child] = depth[node] + 1;
        up[child][0] = node;
        for (int l = 1; l < LOG; l++) {
            up[child][l] = up[up[child][l-1]][l-1];
        }
        dfs(child);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) 
        swap(u, v);

    int k = depth[u] - depth[v];
    for (int l = LOG-1; l >= 0; l--) {
        if ((1 << l) & k) {
            u = up[u][l];
        }
    }

    if (u == v)
        return u;

    for (int l = LOG-1; l >= 0; l--) {
        if (up[u][l] != up[v][l]) {
            u = up[u][l];
            v = up[v][l];
        }
    }

    return up[u][0];
}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    depth.resize(n);
    up.resize(n, vector<int>(LOG));
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int node;
            cin >> node;
            tree[i].push_back(node);
        }
    }

    dfs(0);

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << get_lca(u, v) << endl;
    }
}