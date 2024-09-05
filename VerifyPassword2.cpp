#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i];
        }
        auto b = a;
        sort(a.begin(), a.end());
        if (a == b) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}