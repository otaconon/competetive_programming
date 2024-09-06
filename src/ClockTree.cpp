#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n;
vector<vector<int>> tree;
vector<int> clocks;

vector<bool> vis;
vector<bool> coloring;
void dfs(int node, int color) {
    if (vis[node])
        return;

    vis[node] = true;
    coloring[node] = color;

    for (int child : tree[node]) {
        dfs(child, !color);
    }
}

int main() {
    setIO("clocktree");
    cin >> n;
    clocks.resize(n);
    tree.resize(n);
    vis.resize(n);
    coloring.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> clocks[i];
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, 0);

    int g1 = 0, g2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (!coloring[i]) {
            g1 += clocks[i];
            cnt1++;
        }
        else {
            g2 += clocks[i];
            cnt2++;
        }
    }

    if ((g1%12) == (g2%12)) {
        cout << n << endl;
    }
    else if ((g1 % 12) == ((g2 + 1) % 12)) {
        cout << cnt1 << endl;
    }
    else if (((g1 + 1) % 12) == (g2 % 12)) {
        cout << cnt2 << endl;
    }
    else {
        cout << 0 << endl;
    }
}
