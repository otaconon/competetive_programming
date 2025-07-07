#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "Takahashi") {
            ans++;
        }
    }

    cout << ans << endl;
}