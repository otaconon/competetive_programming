#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(7);
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[s[i] - 65]++;
        }
        int ans = 0;
        for (int i = 0; i < 7; i++) {
            ans += max(0, m - a[i]);
        }

        cout << ans << endl;
    }
}