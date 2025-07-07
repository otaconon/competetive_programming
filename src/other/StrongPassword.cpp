#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        string ans = "";
        ans += s[0];
        bool added = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i] && !added) {
                char new_letter = s[i]+1;
                if (new_letter > 122)
                    new_letter = 97;
                ans += new_letter;
                added = true;
            }
            ans += s[i];
        }

        if (!added) {
            if (s[n-1]+1 > 122)
                ans += 97;
            else
                ans += s[n-1]+1;
        }

        cout << ans << endl;
    }
}