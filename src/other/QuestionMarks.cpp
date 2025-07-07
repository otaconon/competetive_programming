#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        vector<int> a(6);
        cin >> s;
        for (int i = 0; i < 4 * n; i++) {
            a[s[i] - 63]++;
        }

        int ans = 0;
        ans += min(a[2], n);
        ans += min(a[3], n);
        ans += min(a[4], n);
        ans += min(a[5], n);

        cout << ans << endl;
    }
    
}