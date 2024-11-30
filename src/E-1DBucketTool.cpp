#include "bits/stdc++.h"

using namespace std;

class UnionFind {
public:
  UnionFind(vector<int>& vec) {
    rank.resize(vec.size(), 1);
    parent = vec;
    cnt.resize(vec.size(), 1);
  }

  int find(int u) {
    if (parent[u] == u)
      return u;
    return find(parent[u]);
  }

  int getColorCount(int u) {
    return cnt[find(u)];
  }


  // Needs introduction of a color array. Currently it works as if changing disconnected segments affect each other.
  void paint(int u, int c) {
    unify(u, c);
    
    if (u-1 >= 0 && parent[find(u-1)] == c)
      unify(u-1, u);
    if (u+1 < parent.size() && parent[find(u+1)] == c)
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
      int x;
      cin >> x;
      x--;

      cout << uf.getColorCount(x) << endl;
    }
  }
}