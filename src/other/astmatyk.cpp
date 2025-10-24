#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
  vector<int> parent;
  
  DSU(int n) : parent(n+1) {
    iota(parent.begin(), parent.end(), 0);
  }
  
  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  
  void unite(int x, int y) {
    parent[find(x)] = find(y);
  }
  
  bool connected(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  cin >> n >> m;
  vector<int> h(n+1);
  
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<pair<int,int>> peaks;
  for (int i = 1; i <= n; i++) {
    peaks.push_back({h[i], i});
  }
  sort(peaks.begin(), peaks.end());
  
  DSU dsu(n);
  set<int> vis;
  for (auto [height, u] : peaks) {
    vis.insert(u);
    
    for (int v : adj[u]) {
      if (vis.count(v)) {
        dsu.unite(u, v);
      }
    }
    
    if (dsu.connected(1, n)) {
      cout << height << '\n';
      return 0;
    }
  }
}