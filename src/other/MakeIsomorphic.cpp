#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mg, mh;
    cin >> mg;
    vector<set<int>> g(n), h(n);

    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    cin >> mh;
    for (int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        h[u].insert(v);
        h[v].insert(u);
    }

    vector<vector<int>> a(n-1, vector<int>(n));
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    long long ans = LLONG_MAX;

    do {
        set<pair<int, int>> bridges;

        vector<set<int>> new_g(n);
        for (int i = 0; i < n; i++) {
            for (auto& node : g[i]) {
                new_g[p[i]].insert(p[node]);
            }
        }

        long long cost = 0;
        if (p == std::vector<int>{3, 0, 1, 4, 2}) {
            int x = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (new_g[i].count(j) != h[i].count(j)) {
                    bridges.insert({min(i, j), max(i, j)});
                }
            }
        }

        for (auto& bridge : bridges) {
            cost += a[bridge.first][bridge.second];
        }
        
        ans = min(ans, cost);

    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
}