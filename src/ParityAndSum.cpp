#include <bits/stdc++.h>

/*
to make all numbers even we need to have a big odd number, and combine every odd number with it.
at the end only the greatest number will be left which we can do nothing about

to make all numbers odd we need to have a either a big even or odd number, next we can either combine
every odd number with the big even or every even with the big odd.
the first case will take odd_cnt + 1
the second can will take even_cnt
*/

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> even;
        vector<int> odd;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2) {
                odd.push_back(a[i]);
            }
            else {
                even.push_back(a[i]);
            }
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        int sz1 = odd.size(), sz2 = even.size();

        if (n == 1 || sz1 == n || sz2 == n) {
            cout << 0 << endl;
            continue;
        }

        int ans = sz2;
        long long sum = odd[sz1-1];
        for (auto x : even) {
            if (x < sum) {
                sum += x;
            }
            else {
                ans += 1;
                break;
            }
        }

        cout << ans << endl;
        
    }
}