#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int best = 1;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            cnt++;
            best = max(best, cnt);
        }
        else {
            cnt = 1;
        }
            
    }

    cout << best << endl;
}