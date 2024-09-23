#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
    DSU(vector<int>&& vec)
        : up(vec)
    {
        mx.resize(up.size());
        for (int i = 0; i < up.size(); i++) {
            mx[i].push_back(i);
        }
        members.resize(up.size(), 1);
    }

    int find(int u) {
        if (up[u] == u)
            return u;
        return up[u] = find(up[u]);
    }

    void unify(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (members[u] < members[v])
            swap(u, v);

        mx[u].insert(mx[u].end(), mx[v].begin(), mx[v].end());
        sort(mx[u].rbegin(), mx[u].rend());
        mx[u] = vector<int>(mx[u].begin(), mx[u].begin()+min(10, (int)mx[u].size()));

        members[u] += members[v];
        up[v] = u;
    }

    int getMx(int u, int k) {
        u = find(u);
        if (mx[u].size() < k)
            return -1;

        return mx[u][k-1] + 1;
    }

private:
    vector<int> up;
    vector<int> members;

    vector<vector<int>> mx;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    DSU dsu(move(a));
    
    while (q--) {
        int x, u, v;
        cin >> x >> u >> v;
        u--;

        if (x == 1) {
            v--;
            dsu.unify(u, v);
        }
        else {
            cout << dsu.getMx(u, v) << endl;
        }
    }
}