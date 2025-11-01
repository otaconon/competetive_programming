#include "bits/stdc++.h"

using namespace std;

struct Dsu {
  vector<int> p;

  Dsu(int n) : p(n) {
    iota(p.begin(), p.end(), 0);
  }

  int find(int u) {
    if (p[u] == u) return u;
    return find(p[u]);
  }

  void unify(int u, int v) {
    u = find(u);
    v = find(v);
    p[u] = p[v];
  }

  bool connected(int u, int v) {
    return find(u) == find(v);
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Dsu dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    dsu.unify(u, v);
  }

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    cout << (dsu.connected(u, v) ? "TAK\n" : "NIE\n");
  }
}