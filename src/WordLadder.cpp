#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] != t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}