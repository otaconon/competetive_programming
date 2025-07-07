#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a;
vector<vector<int>> dist;
vector<bool> vis;

int get_furthest(int node) {
    queue<int> q;
    q.push(node);
    vector<bool> visited(a.size());
    int furthest = node;
    while (!q.empty()) {
        int cNode = q.front();
        furthest = cNode;
        q.pop();
        visited[cNode] = true;
        for (int child : a[cNode]) {
            if (!visited[child]) {
                q.push(child);
            }
        }
    }

    return furthest;
}

void calculate_distances(int node, int idx, int d) {
    if (vis[node]) {
        return;
    }

    vis[node] = true;

    dist[idx][node] = d;

    for (int child : a[node]) {
        calculate_distances(child, idx, d+1);
    }
}


int main() {
    cin >> n;
    a.resize(n+1);
    dist.resize(2, vector<int>(n+1));
    vis.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int u = get_furthest(1);
    int v = get_furthest(u);

    vis = vector<bool>(n+1);
    calculate_distances(u, 0, 0);
    vis = vector<bool>(n+1);
    calculate_distances(v, 1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(dist[0][i], dist[1][i]) << ' ';
    }
}