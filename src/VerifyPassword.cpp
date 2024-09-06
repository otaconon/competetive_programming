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
        vector<char> digits, letters;
        if (isdigit(s[0]))
            digits.push_back(s[0]);
        else
            letters.push_back(s[0]);

        bool end = false;
        for (int i = 1; i < n; i++) {
            if (isdigit(s[i])) {
                digits.push_back(s[i]);
                if (!isdigit(s[i-1])) {
                    cout << "NO" << '\n';
                    end = true;
                    break;
                }
            }
            else {
                letters.push_back(s[i]);
            }
        }

        if (end)
            continue;

        auto sd = digits, sl = letters;
        sort(sd.begin(), sd.end());
        sort(sl.begin(), sl.end());

        if (sd == digits && sl == letters) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}