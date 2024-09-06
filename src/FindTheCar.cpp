#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<long long> a(k+1);
        vector<long long> b(k+1);
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < q; i++) {
            long long d;
            cin >> d;

            auto it = upper_bound(a.begin(), a.end(), d);
                
            int idx = it - a.begin();
            if (a[idx-1] == d) {
                cout << b[idx-1] << " ";
                continue;
            }      
            
            long long ans = b[idx-1] + (d - a[idx-1]) * (b[idx] - b[idx-1]) / (a[idx] - a[idx-1]);
            cout << ans << " ";
        }

        cout << endl;
    }
}