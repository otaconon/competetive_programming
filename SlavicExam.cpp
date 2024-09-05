#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        
        string ans = "";
        bool found = false;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (found) {
                if (s[i] == '?')
                    ans += 'a';
                else {
                    ans += s[i];
                }
                continue;
            }

            if (s[i] == '?') {
                ans += t[j];
                j++;
                if (j == t.size()) {
                    found = true;
                }
                continue;
            }

            if (s[i] == t[j]) {
                j++;
            }

            ans += s[i];
            if (j == t.size()) {
                found = true;
            }
        }

        if (found) {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
    }
}