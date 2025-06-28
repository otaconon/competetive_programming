#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const int MAX_W = 1024;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
    }

    vector<vector<int>> dist(n, vector<int>(MAX_W, -1));

    queue<pair<int,int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [u, s] = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            int ns = s ^ w;
            if (dist[v][ns] == -1) {
                dist[v][ns] = dist[u][s] + 1;
                q.push({v, ns});
            }
        }
    }

    int best = -1;
    for (int s = 0; s < MAX_W; ++s)
        if (dist[n-1][s] != -1 && (best == -1 || s < best))
            best = s;

    cout << best << '\n';
    return 0;
}