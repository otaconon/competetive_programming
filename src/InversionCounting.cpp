#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Tree<int> tr;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            
            cnt += i - tr.order_of_key(x);
            tr.insert(x);
        }

        cout << cnt << endl;
    }
}