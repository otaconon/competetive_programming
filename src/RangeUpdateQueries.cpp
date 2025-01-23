#include <bits/stdc++.h>

using namespace std;

template<typename T>
class SegmentTree {
public:
    SegmentTree(vector<T>& vec) : len(vec.size()), t(std::vector<T>(vec.size()*4)) {
        build(vec, 1, 0, len-1);
    }

    void update(int v, int lt, int rt, int l, int r, int val) {
        if (l > r)
            return;
        if (lt == l && rt == r) {
            t[v] += val;
        }
        else {
            int m = (lt + rt) / 2;
            update(v*2, lt, m, l, min(m, r), val);
            update(v*2+1, m+1, rt, max(m+1, l), r, val);
        }
    }

    T query(int v, int l, int r, int idx) {
        if (l == r)
            return t[v];
        
        int m = (l + r) / 2;
        if (idx <= m)
            return t[v] + query(v*2, l, m, idx);
        else
            return t[v] + query(v*2+1, m+1, r, idx);
    }
    

private:
    int len = 0;
    vector<T> t;

    void build(vector<T>& vec, int v, int l, int r) {
        if (l == r) {
            t[v] = vec[l];
        }
        else {
            int m = (l + r) / 2;
            build(vec, v*2, l, m);
            build(vec, v*2+1, m+1, r);
            t[v] = 0;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (auto& x : a)
        cin >> x;

    SegmentTree<long long> t(a);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--; b--;
            t.update(1, 0, n-1, a, b, u);
        }
        else {
            int k;
            cin >> k;
            k--;
            cout << t.query(1, 0, n-1, k) << endl;
        }
    }
}