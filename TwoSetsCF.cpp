#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    UnionFind(int sz) {
        root.resize(sz);
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }

        h.resize(sz, 0);
    }

    int find(int x) {
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }

    void unify(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (h[u] > h[v]) {
            root[v] = u;
            h[u] = max(h[u], h[v]+1);
        }
        else {
            root[u] = v;
            h[v] = max(h[v], h[u]+1);
        }
    }

private:
    vector<int> root;
    vector<int> h;
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    map<int, int> at;
    for (int i = 0; i < n; i++) {
        at[p[i]] = i;
    }

    UnionFind uf(n);

    vector<int> canA(n), canB(n);
    for (int i = 0; i < n; i++) {
        if (at.count(a - p[i])) {
            canA[i] = true;
            uf.unify(i, at[a - p[i]]);
        }
        if(at.count(b - p[i])) {
            canB[i] = true;
            uf.unify(i, at[b - p[i]]);
        }
    }

    vector<int> can(n, 3);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        if (canA[i]) mask += 1;
        if (canB[i]) mask += 2;
        can[uf.find(i)] &= mask;
    }

    for (int i = 0; i < n; i++) {
        if (!can[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        int comp_mask = can[uf.find(i)];
		if (comp_mask == 1) {
			cout << 0 << " ";
		} else {
			cout << 1 << " ";
		}
    }

}