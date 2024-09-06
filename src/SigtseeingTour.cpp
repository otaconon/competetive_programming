#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 1LL << 60;

int n, m;
vector<tuple<int, int, int>> g;

int q;
vector<int> b;

vector<vector<long long>> d;
void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    d.resize(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    g.resize(m);
    for (int i = 0; i < m; i++) {
        long long u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        g[i] = {u, v, t};
        d[u][v] = min(d[u][v], t);
        d[v][u] = min(d[v][u], t);
    }

    floyd_warshall();

    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        b.resize(k, 0);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            b[i]--;
        }

        sort(b.begin(), b.end());
        long long path_len = LLONG_MAX;
        do {
            for (int i = 0; i < 1 << k; i++) {
                long long new_len = 0;
                int prev = 0;
                for (int j = 0; j < k; j++) {
                    int u = get<0>(g[b[j]]);
                    int v = get<1>(g[b[j]]);
                    if (i & (1 << j)) {
                        swap(u, v);
                    }
                    new_len += d[prev][u] + get<2>(g[b[j]]);
                    prev = v;
                }
                
                path_len = min(path_len, new_len + d[prev][n-1]);
            }
        } while (std::next_permutation(b.begin(), b.end()));

        cout << path_len << endl;
    }
   
}