#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool was_rice = false;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'R')
            was_rice = true;
        if (s[i] == 'M') {
            if (was_rice) {
                cout << "Yes" << endl;
                return 0;
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
}