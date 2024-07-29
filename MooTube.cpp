#include "bits/stdc++.h"
#include <iostream>

using namespace std;

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
    cin >> n >> Q;
    vector<tuple<int, int, int>> a(n-1);
    for (int i = 0; i < n-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        p--; q--;
        a[i] = {r, p, q};
    }

    map<int, int> b;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        b[x] = i;
    }

    sort(a.begin(), a.end());

    int j = 0;
    UnionFind uf(n-1);
    vector<int> ans(n-1);
    for (auto [k, i] : b) {
        while (get<0>(a[j]) <= k && j < n-1) {
            uf.unify(get<1>(a[j]), get<2>(a[j]));
            j++;
        }
        ans[i] = uf.getNumOfComp(get<1>(a[0]));
    }

    for (auto x : ans) {
        cout << x << endl;
    }
}