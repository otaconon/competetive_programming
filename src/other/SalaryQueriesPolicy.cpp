#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> ar(n+1);
    Tree<pair<int, int>> t;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        t.insert({ar[i], i});
    }

    while (q--) {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;
        if (op == '!') {
            t.erase({ar[a], a});
            ar[a] = b;
            t.insert({ar[a], a});
        }
        else {
            cout << t.order_of_key({b, INT_MAX}) - t.order_of_key({a-1, INT_MAX}) << endl;
        }
    }
    return 0;
}