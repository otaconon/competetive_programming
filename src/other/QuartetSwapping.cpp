#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int size) : n(size) {
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            ret += bit[r];
        return ret;
    }

    void add (int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

private:
    vector<int> bit;
    int n;
};

int inversion_parity(const vector<int>& v) {
    int n = (int)v.size();
    FenwickTree bit(n);
    int par = 0;
    for (int i = n-1; i >= 0; --i) {
        int idx = v[i]-1;
        par ^= (bit.sum(idx) & 1);
        bit.add(idx, 1);
    }
    return par;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;  cin >> t;
    while (t--) {
        int n;  cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        vector<int> odd, even;
        for (int i = 0; i < n; ++i)
            (i & 1 ? even : odd).push_back(a[i]);

        sort(odd.begin(),  odd.end());
        sort(even.begin(), even.end());

        vector<int> ans(n);
        for (int i = 0; i < (int)odd.size();  ++i) ans[i*2]   = odd[i];
        for (int i = 0; i < (int)even.size(); ++i) ans[i*2+1] = even[i];

        int orig_parity = inversion_parity(a);
        int cand_parity = inversion_parity(ans);

        if (orig_parity != cand_parity) {
            swap(ans[n-3], ans[n-1]);
        }

        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}