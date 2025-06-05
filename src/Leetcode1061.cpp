#include <vector>
#include <string>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) {
    parent.resize(n);
    smallest.resize(n);
    for (int i = 0; i < n; i++) {
      make_set(i);
      smallest[i] = i;
    }
  }
  void make_set(int v) {
    parent[v] = v;
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return find_set(parent[v]);
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b)
      return;

    if (smallest[b] < smallest[a])
      smallest[a] = smallest[b];
    parent[b] = a;
  }

  int get_smallest(int v) {
    return smallest[find_set(v)];
  }

private:
  vector<int> parent;
  vector<int> smallest;
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        UnionFind uf(27);
        for (int i = 0; i < n; i++) {
          uf.union_sets(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
          ans += char(uf.get_smallest(baseStr[i] - 'a') + 'a');
        }

        return ans;
    }
};

int main() {

}