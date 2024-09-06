#include <bits/stdc++.h>

using namespace std;

/*
definitely can't place on any bet more 

*/

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> k(n);
        pair<int, ll> max_k = {-1, -1};
        for (int i = 0; i < n; i++) {
            cin >> k[i];
            if (k[i] > max_k.second) {
                max_k = {k[i], i};
            }
        }

        int ans = -1;
        vector<int> cnt(k.size());
        for (int j = 0; j < 1e5; j++) {
            fill(cnt.begin(), cnt.end(), 0);
            bool is_valid = true;

            for (size_t i = 0; i < k.size(); i++) {
                int sub = 0;
                if (i != max_k.second)
                    sub = 1;

                cnt[i] = (((j-1) * max_k.first) / k[i]);
            }

            long long sum = 0;
            for (size_t i = 0; i < k.size(); i++) {
                sum += cnt[i];
            }

            for (size_t i = 0; i < k.size(); i++) {
                if (sum >= cnt[i] * k[i]) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                ans = j;
                break;
            }
        }

        if (ans != -1) {
            for (int i = 0; i < n; i++) {
                cout << cnt[i] << ' ';
            }
        }
        else {
            cout << -1;
        }
        cout << endl;
    }
}