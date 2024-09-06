#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> a(27);
    for (int i = 0; i < s.size(); i++) {
        a[int(s[i]) - 65]++;
    }

    bool foundOdd = false;
    char oddChar;
    vector<char> ansFront;
    vector<char> ansBack;
    for (int i = 0; i < 27; i++) {
        if (a[i] % 2) {
            if (foundOdd) {
                cout << "NO SOLUTION" << '\n';
                return 0;
            }
            else {
                foundOdd = true;
                oddChar = char(i + 65);
            }
        }
        for (int j = 0; j < a[i] / 2; j++) {
            ansFront.push_back(char(i + 65));
        }
        for (int j = 0; j < a[i] / 2; j++) {
            ansBack.push_back(char(i + 65));
        }
    }
    
    for (auto x : ansFront) {
        cout << x;
    }

    if (foundOdd) cout << oddChar;

    for (int i = ansBack.size() - 1; i >= 0; i--) {
        cout << ansBack[i];
    }
}