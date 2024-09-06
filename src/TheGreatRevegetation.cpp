#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
map<pair<int, int>, int> coloring;

bool possible = true;
vector<int> comp;
vector<bool> visited;
void dfs(int node, int prev) {
    if (visited[node]) return;
    visited[node] = true;
    

    for (auto &neigh: adj[node]) {
        if (!coloring[{node, neigh}]) {
            if (comp[neigh] != -1 && comp[neigh] != comp[node]) {
                possible = false;
            }
            comp[neigh] = comp[node];
        }
        else {
            if (comp[node]) {
                if (comp[neigh] == 1) {
                    possible = false;
                }
                comp[neigh] = 0;
            }
            else {
                if (comp[neigh] == 0) {
                    possible = false;
                }
                comp[neigh] = 1;
            }
        }
        dfs(neigh, node);
    }
}

int main() {
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    comp.resize(n + 1, -1);
    
    for (int i = 0; i < m; i++) {
        char color;
        int u, v;
        cin >> color >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if (color == 'S') {
            coloring[{u, v}] = 0;
            coloring[{v, u}] = 0;
        }
        else if (color == 'D') {
            coloring[{u, v}] = 1;
            coloring[{v, u}] = 1;
        }
    }

    int comp_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp[i] = 0;
            dfs(i, -1);
            comp_cnt++;
        }
    }

    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1;
    for (int i = 0; i < comp_cnt; i++) {cout << 0;}
    cout << endl;
}