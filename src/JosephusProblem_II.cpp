#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, k;

void solve() {
    ordered_set circle;
    for (int i = 1; i <= n; i++) {
        circle.insert(i);
    }

    int start_val = k;
    while (!circle.empty()) {

        set<int> to_delete;
        for (int i = start_val % circle.size(); i < circle.size(); i+=k+1) {
            to_delete.insert(*circle.find_by_order(i));
            start_val = i+k+1 - circle.size();
        }

        for (auto it : to_delete) {
            cout << it << ' ';
            circle.erase(it);
        }
    }
}


int main() {
    
    cin >> n >> k;

    solve();
}