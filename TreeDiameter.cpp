#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> t;

int get_furthest(int node, vector<vector<int>>& tree) {
    queue<int> q;
    q.push(node);
    vector<bool> visited(tree.size());
    int furthest = node;
    while (!q.empty()) {
        int cNode = q.front();
        furthest = cNode;
        q.pop();
        visited[cNode] = true;
        for (int child : tree[cNode]) {
            if (!visited[child]) {
                q.push(child);
            }
        }
    }

    return furthest;
}

vector<int> vis;
int get_distance(int node, int dest, int depth, vector<vector<int>>& tree) {
    if (node == dest) {
        return depth;
    }

    if (vis[node]) {
        return -1;
    }

    vis[node] = true;

    for (int child : tree[node]) {
        int dist = get_distance(child, dest, depth+1, tree);
        if (dist != -1) {
            return dist;
        }
    }

    return -1;
}

int main() {
    cin >> n;
    t.resize(n+1);
    vis.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    int a = get_furthest(1, t);
    int b = get_furthest(a, t);
    int ans = get_distance(a, b, 0, t);

    cout << ans <<  endl;
}