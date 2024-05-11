#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    size_t n = s.size(), m = t.size();

    for (int i = 0, j = 0; j < m; j++) {
        if (s[i] == t[j]) {
            cout << j + 1 << ' ';
            i++;
        }
    }
}