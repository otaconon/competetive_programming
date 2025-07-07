#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        for (auto& x : a)
            x = abs(x);

        int y = a[0];
        sort(a.begin(), a.end());

        int m = n / 2;
        int diff = (find(a.begin(), a.end(), y) - a.begin()) - m;
        
        if (diff > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}