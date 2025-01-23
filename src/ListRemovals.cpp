#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n;
    cin >> n;
    Tree<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t.insert(pair<int, int>{i, x});
    }
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = t.find_by_order(x-1);
        cout << it->second << ' ';
        t.erase(it);
    }

}