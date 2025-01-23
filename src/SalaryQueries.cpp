#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
public:
    SegmentTree(int n) : len(n), t(n*4) {
    }

    void update(int v, int l, int r, int idx, int diff) {
        if (l == r) {
            t[v] += diff;
        }
        else {
            int m = (l + r) / 2;
            if (idx <= m) {
                update(v*2, l, m, idx, diff);
            }
            else {
                update(v*2+1, m+1, r, idx, diff);
            }
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    int query(int v, int lt, int rt, int l, int r) {
        if (l > r)
            return 0;
        
        if (lt == l && rt == r) {
            return t[v];
        }
        else {
            int mt = (lt + rt) / 2;
            return query(v*2, lt, mt, l, min(mt, r)) + query(v*2+1, mt+1, rt, max(l, mt+1), r);
        }
    }

    int len;
    vector<T> t;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> ar(n);
    for (auto& x : ar)
        cin >> x;

    vector<int> vals = ar;
    vector<array<int, 3>> queries;
    while (q--) {
        char op;
        cin >> op;
        int a, b;
        cin >> a >> b;
        queries.push_back({op == '?', a, b});
        if (op == '!')
            vals.push_back(b);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();
    SegmentTree<int> st(m);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vals.begin(), vals.end(), ar[i]) - vals.begin();
        st.update(1, 0, m-1, idx, 1);
    }

    for (auto& [op, a, b] : queries) {
        if (op) {
            int idx1 = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
            int idx2 = upper_bound(vals.begin(), vals.end(), b) - vals.begin() - 1;
            cout << st.query(1, 0, m-1, idx1, idx2) << endl;
        }
        else {
            a--;
            int idx1 = lower_bound(vals.begin(), vals.end(), ar[a]) - vals.begin();
            st.update(1, 0, m-1, idx1, -1);
            ar[a] = b;
            int idx2 = lower_bound(vals.begin(), vals.end(), ar[a]) - vals.begin();
            st.update(1, 0, m-1, idx2, 1);
        }
    }
    return 0;
}