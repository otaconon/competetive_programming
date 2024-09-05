#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

class UnionFind {
public:
    UnionFind(int sz) {
        root.resize(sz);
        numOfComp.resize(sz, 1);
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

    void unify(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        if (h[a] > h[b]) {
            numOfComp[a] += numOfComp[b];
            root[b] = a;
            h[a] = max(h[a], h[b]+1);
        }
        else {
            numOfComp[b] += numOfComp[a];
            root[a] = b;
            h[b] = max(h[b], h[a]+1);
        }
    }

    int getNumOfComp(int x) {
        return numOfComp[find(x)];
    }

private:
    vector<int> root;
    vector<int> h;
    vector<int> numOfComp;
};

int n, Q;

int main() {
    setIO("mootube");
    cin >> n >> Q;
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        p--; q--;
        a[i] = {r, p, q};
    }

    vector<tuple<int, int, int>> b(Q);
    for (int i = 0; i < Q; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        b[i] = {x1, x2-1, i};
    }

    sort(b.rbegin(), b.rend());
    sort(a.rbegin(), a.rend());

    int j = 0;
    UnionFind uf(n);
    vector<int> ans(Q);
    for (auto [k, x, i] : b) {
        while (get<0>(a[j]) >= k && j < n-1) {
            uf.unify(get<1>(a[j]), get<2>(a[j]));
            j++;
        }
        ans[i] = uf.getNumOfComp(x) - 1;
    }

    for (auto x : ans) {
        cout << x << endl;
    }
}