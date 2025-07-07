#include "bits/stdc++.h"

using namespace std;

class UnionFind {
public:
  UnionFind(vector<int>& vec) {
    parent = vec;
    color = vec;
    rank.resize(vec.size(), 1);
    cnt.resize(vec.size(), 1);
    color_cnt.resize(vec.size(), 1);
  }

  int find(int u) {
    if (parent[u] != u)
      parent[u] = find(parent[u]);
    return parent[u];
  }

  int getColorCount(int c) {
    return color_cnt[c];
  }

  void paint(int u, int c) {
    int p = find(u);
    color_cnt[color[p]] -= cnt[p];
    color[p] = c;
    color_cnt[c] += cnt[p];
    
    if (u-1 >= 0 && color[find(u-1)] == c)
      unify(u-1, u);
    if (u+1 < parent.size() && color[find(u+1)] == c)
      unify(u, u+1);
  }

  void unify(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return;
    
    if (rank[u] < rank[v])
      swap(u, v);
    
    cnt[u] += cnt[v];
    parent[v] = u;
    if (rank[u] == rank[v])
      rank[u]++;
  }

private:
  vector<int> parent;
  vector<int> rank;
  vector<int> cnt;
  vector<int> color;
  vector<int> color_cnt;
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  iota(a.begin(), a.end(), 0);

  UnionFind uf(a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, c;
      cin >> x >> c; x--; c--;

      uf.paint(x, c);
    }
    else {
      int c;
      cin >> c;
      c--;

      cout << uf.getColorCount(c) << endl;
    }
  }
}