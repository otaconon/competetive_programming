#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    for (int w = 1; w < s.size()-1; w++) {
        for (int c = 0; c <= w; c++) {
            string new_s = "";
            for (int i = 0; i + c < s.size(); i += w) {
                new_s += s[i+c];
            }
            if (new_s == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}