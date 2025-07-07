#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<vector<long long>> dist;

int main() {
    cin >> n >> m >> q;
    dist.resize(n, vector<long long>(n, LLONG_MAX/2));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min(dist[v][u], w);
        dist[v][u] = min(dist[u][v], w);
    }

    for (int mid = 0; mid < n; mid++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][mid] + dist[mid][v]);
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dist[u][v] == LLONG_MAX/2)
            cout << -1 << endl;
        else
            cout << dist[u][v] << endl;
    }
}