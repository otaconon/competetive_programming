#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n*2);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < 2*n-2; i++) {
        if (a[i] == a[i+2]) {
            ans++;
        } 
    }

    cout << ans << endl;
}