#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using Tree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("bphoto");

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;

    Tree<ll> cows;
    for (int i = 0; i < n; i++)
        cows.insert(a[i]);

    int ans = 0;
    Tree<ll> sol;
    for (int i = 0; i < n; i++) {
        sol.insert(a[i]);
        int l = sol.order_of_key(a[i]);
        int r = cows.order_of_key(a[i]) - l;
        if (l > r*2 || r > l*2)
            ans++;
    }

    cout << ans << endl;
}