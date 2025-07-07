#include <bits/stdc++.h>

using namespace std;

constexpr int LOG = 20;

int n, q;
vector<vector<int>> up;
vector<int> depth;
vector<set<int>> tree;

void dfs(int node, int parent, int d) {
    depth[node] = d;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node, d+1);
        }
    }
}

int main() {
    cin >> n >> q;
    up.resize(n, vector<int>(LOG));
    tree.resize(n); 
    depth.resize(n);

    for (int l = 0; l < LOG; l++) {
        up[0][l] = -1;
    }
    for (int i = 1; i < n; i++) {
        cin >> up[i][0];
        up[i][0]--;
    }

    for (int i = 0; i < n; i++) {
        if (up[i][0] != -1)
            tree[up[i][0]].insert(i);
    }

    for (int l = 1; l < LOG; l++) {
        for (int i = 1; i < n; i++) {
            if (up[i][l-1] != -1)
                up[i][l] = up[up[i][l-1]][l-1];
            else
                up[i][l] = -1;
        }
    }
    
    dfs(0, -1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int k = depth[u] - depth[v];
        for (int l = LOG-1; l >= 0; l--) {
            if ((1 << l) & k) {
                u = up[u][l];
            }
        }

        if (u == v) {
            cout << u + 1 << endl;
            continue;
        }

        for (int l = LOG-1; l >= 0; l--) {
            if(up[u][l] != up[v][l]) {
                u = up[u][l];
                v = up[v][l];
            }
            
        }
        
        cout << up[u][0] + 1 << endl;
    }
}