#include "bits/stdc++.h"

using namespace std;

struct Dsu {
  vector<int> p;
  vector<int> sz;
  int max_sz = 0;

  Dsu(int n) : p(n), sz(n, 1) {
    iota(p.begin(), p.end(), 0);
  }

  int find(int u) {
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
  }

  void unify(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    p[v] = u;
    sz[u] += sz[v];
    max_sz = max(max_sz, sz[u]);
  }

  bool connected(int u, int v) {
    return find(u) == find(v);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  vector<vector<int>> g(n, vector<int>(n));
  vector<pair<int, pair<int, int>>> trees;
  trees.reserve(n*n);
  for (int i = 0; i < n; i++)  {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
      trees.push_back({g[i][j], {i, j}});
    }
  }

  sort(trees.begin(), trees.end());
  Dsu dsu(n*n);
  set<int> active;
  for (auto& [h, coords] : trees) {
    auto [i, j] = coords;
    active.insert(n*i + j);

    if (i+1 < n && active.count(n*(i+1) + j)) dsu.unify(n*i + j, n*(i+1) + j);
    if (i-1 >= 0 && active.count(n*(i-1) + j)) dsu.unify(n*i + j, n*(i-1) + j);
    if (j+1 < n && active.count(n*i + (j+1))) dsu.unify(n*i + j, n*i + (j+1));
    if (j-1 >= 0 && active.count(n*i + (j-1))) dsu.unify(n*i + j, n*i + (j-1));
  
    if (dsu.max_sz >= d) {
      cout << h << '\n';
      return 0;
    }
  }
}