#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }

        sort(a.rbegin(), a.rend());

        bool ans = false;
        for (int i = 0; i <= n; i++) {
            if (a[i] % 2) {
                ans = true;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}