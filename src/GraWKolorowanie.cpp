#include <bits/stdc++.h>

/*
To compute the solution for n <= 2000 lca can be used.
First we have to compute up[node], so that we can then for every combination of starting points
comptute lca. The answer to whether player one can win, is the same as answer to the question:
which player can get to lca first, and by that blocking off player1. Then we have to compute
how many fields are on each player side, only if the number of fields on players1 side is greater then on player2 can he win.
*/

using namespace std;

constexpr int LOG = 20;

int n;
vector<vector<int>> tree;
int sa, sb, q;

vector<vector<int>> up;
vector<int> depth;
vector<int> children_count;
void compute_up(int node) {
    for (auto child : tree[node]) {
        depth[child] = depth[node] + 1;
        up[child][0] = node;
        for (int l = 1; l < LOG; l++) {
            up[child][l] = up[up[child][l-1]][l-1];
        }
        compute_up(child);
    }
}

int compute_children_count(int node, int parent) {
    children_count[node] = 1;
    for (auto child : tree[node]) {
        if (child != parent)
            children_count[node] += compute_children_count(child, node);
    }

    return children_count[node];
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int k = depth[u] - depth[v];
    for (int l = LOG-1; l >= 0; l--) {
        if (k & (1 << l)) {
            u = up[u][l];
        }
    }

    if (u == v) {
        return u;
    }

    for (int l = LOG-1; l >= 0; l--) {
        if (up[u][l] != up[v][l]) {
            u = up[u][l];
            v = up[v][l];
        }
    }

    return up[u][0];
}

int main() {
    cin >> n;
    tree.resize(n);
    up.resize(n, vector<int>(LOG));
    depth.resize(n);
    children_count.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cin >> sa >> sb >> q;


}