#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> c;
vector<bool> visited;

double expected_value = 0;

void dfs(int node, double prob, int dist) {
    visited[node] = true;

    int unvisited = 0;
    for (auto child : c[node]) {
        if (!visited[child]) {
            unvisited++;
        }
    }

    if (unvisited == 0) {
        expected_value += prob * dist;
    }

    for (auto child : c[node]) {
        if (!visited[child]) {
            dfs(child, prob / unvisited, dist+1);
        }
    }
}

int main() {
    cin >> n;
    c.resize(n+1);
    visited.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    dfs(1, 1, 0);

    cout << fixed << setprecision(15) << expected_value << endl;
}