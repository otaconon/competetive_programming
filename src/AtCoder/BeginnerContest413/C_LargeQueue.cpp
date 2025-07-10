#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    vector<pair<int, int>> add;
    int i = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int c, x;
            cin >> c >> x;
            add.emplace_back(c, x);
        }
        else if (op == 2) {
            int k;
            cin >> k;
            
            long long sum = 0;
            while (k > 0) {
                auto &bucket = add[i];
                long long take = min(bucket.first, k);
                sum += take * bucket.second;
                bucket.first -= take;
                k -= take;
                if (bucket.first == 0) 
                    i++;
            }
            
            cout << sum << '\n';
        }
    }
}