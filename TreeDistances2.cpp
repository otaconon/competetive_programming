#include <bits/stdc++.h>

using namespace std;

long long n;
vector<vector<long long>> a;

vector<bool> vis;
long long root_distances = 0;
void dfs(long long node, long long d) {
    if (vis[node]) {
        return;
    }

    vis[node] = true;
    root_distances += d;

    for (long long child : a[node]) {
        dfs(child, d+1);
    }
}

int main() {
    cin >> n;
    a.resize(n+1);
    vis.resize(n+1);
    for (long long i = 0; i < n-1; i++) {
        long long u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<bool> visited(n+1);
    queue<long long> q;

    vector<long long> treeSizes(n+1);
    vector<long long> subTrees(n+1, 1);
    for (long long i = 1; i <= n; i++) {
        treeSizes[i] = a[i].size();
        if (a[i].size() == 1) {
            treeSizes[i]--;
            q.push(i);
        }
    }

    long long root = 0;
    while (!q.empty()) {
        long long cNode = q.front();
        q.pop();
        visited[cNode] = true;
        root = cNode;

        for (long long child : a[cNode]) {
            if (visited[child]) {
                subTrees[cNode] += subTrees[child];
            }
        }

        for (long long parent : a[cNode]) {
            if (!visited[parent]) {
                treeSizes[parent]--;
            }
            if (treeSizes[parent] == 1) {
                treeSizes[parent]--;
                q.push(parent);
            }
        }
    }

    dfs(root, 0);

    queue<pair<long long, long long>> q2;
    visited = vector<bool>(n+1);
    q2.emplace(root, root_distances);

    vector<long long> ans(n+1);
    ans[root] = root_distances;
    while (!q2.empty()) {
        auto [cNode, dist] = q2.front();
        q2.pop();
        visited[cNode] = true;

        for (long long child : a[cNode]) {
            if (!visited[child]) {
                long long new_dist = dist - subTrees[child] + (n - subTrees[child]);
                ans[child] = new_dist;
                q2.emplace(child, new_dist);
            }
        }
    }

    for (long long i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}