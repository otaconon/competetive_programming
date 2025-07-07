#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> a(n+1);
    for (int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        a[x] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            cout << i << endl;
        }
    }
}