#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> a;
vector<int> coloring;
bool invalid = false;

void dfs(int node, int color) {
    if (coloring[node] != 0){
        return;
    }

    coloring[node] = color;

    for (int child : a[node]) {
        int new_color = color == 1 ? 2 : 1;
        if (coloring[child] != 0 && coloring[child] != new_color) {
            invalid = true;
        }
        dfs(child, new_color);
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    coloring.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 1);
    }

    if (invalid) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << coloring[i] << ' ';
    }

}