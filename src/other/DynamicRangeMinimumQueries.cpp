#include <bits/stdc++.h>

using namespace std;

void build(vector<int>& a, vector<int>& t, int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    }
    else {
        int m = (l + r) / 2;
        build(a, t, v*2, l, m);
        build(a, t, v*2+1, m+1, r);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

void update(vector<int>& t, int v, int l, int r, int idx, int val) {
    if (l == r) {
        t[v] = val;
    }
    else {
        int m = (l + r) / 2;
        if (idx <= m)
            update(t, v*2, l, m, idx, val);
        else
            update(t, v*2+1, m+1, r, idx, val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int minimum(vector<int>& t, int v, int lt, int rt, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (lt == l && rt == r)
        return t[v];
    
    int m = (lt + rt) / 2;
    return min(minimum(t, v*2, lt, m, l, min(m, r)), minimum(t, v*2+1, m+1, rt, max(l, m+1), r));
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<int> t(4*n, INT_MAX);
    build(a, t, 1, 0, n-1);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        a--;
        if (op == 1) {
            update(t, 1, 0, n-1, a, b);
        }
        else {
            b--;
            cout << minimum(t, 1, 0, n-1, a, b) << endl;;
        }
    }
}