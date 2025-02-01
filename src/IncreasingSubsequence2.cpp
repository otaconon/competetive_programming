#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;

template<typename T>
struct FenwickTree {
    vector<T> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    void update(int r, T val) {
        for (; r <= n; r += (r & (-r)))
            bit[r] = (bit[r] + val) % mod;
    }

    T query(int idx) {
        T res = 0;
        for (; idx; idx -= (idx & (-idx)))
            res = (res + bit[idx]) % mod;
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    FenwickTree<ll> t(n);
    vector<ll> ar(n);
    map<ll, int> comp;
    for (auto& x : ar)
        cin >> x;

    auto sorted = ar;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) {
        comp[sorted[i]] = i+1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int subseq = 1 + t.query(comp[ar[i]]-1);
        ans = (ans + subseq) % mod;
        t.update(comp[ar[i]], subseq);
    }

    cout << ans << endl;
}