#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        if (s.size() == i+1) {
            ans++;
        }
    }

    cout << ans << endl;
}