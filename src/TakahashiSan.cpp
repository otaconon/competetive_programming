#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string a = s.substr(0, 3);
    if (s.substr(0, 3) == "nas") {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}