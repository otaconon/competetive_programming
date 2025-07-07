#include <bits/stdc++.h>

using namespace std;

void set_t(vector<int>& t, int idx, int val) {
    int len = (int)t.size()/2;
    idx += len;
    t[idx] = val;
    for (; idx > 1; idx /= 2) {
        t[idx/2] = min(t[idx], t[idx ^ 1]);
    }
}

int query(vector<int>& t, int l, int r) {
    int mn = INT_MAX;
    int len = (int)t.size()/2;
    for (l += len, r += len; l < r; l /= 2, r /= 2) {
        if (l % 2)
            mn = min(mn, t[l++]);
        if (r % 2)
            mn = min(mn, t[--r]);
    }
    return mn;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> t(2*n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set_t(t, i, x);
    }
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            set_t(t, a-1, b);
        else
            cout << query(t, a-1, b-1) << endl;;
    }
}