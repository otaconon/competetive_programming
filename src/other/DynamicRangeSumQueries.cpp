#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void build(vector<int>& a, vector<ll>& tree, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(a, tree, v*2, tl, tm);
        build(a, tree, v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

void update(vector<ll>& tree, int v, int l, int r, int idx, int val) {
    if (l == r) {
        tree[v] = val;
    }
    else {
        int m = (l + r) / 2;
        if (idx <= m)
            update(tree, v*2, l, m, idx, val);
        else
            update(tree, v*2+1, m+1, r, idx, val);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

long long sum(vector<ll>& tree, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return tree[v];
    
    int m = (tl + tr) / 2;
    return sum(tree, v*2, tl, m, l, min(r, m)) + sum(tree, v*2+1, m+1, tr, max(l, m+1), r);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<ll> tree(4*n);
    build(a, tree, 1, 0, n-1);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l--;

        if (op == 1) {
            update(tree, 1, 0, n-1, l, r);
        }
        else {
            r--;
            cout << sum(tree, 1, 0, n-1, l, r) << endl;
        }
            
    }
}