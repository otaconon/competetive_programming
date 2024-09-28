#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<pair<char, int>> a(s.size());
    for (int i = 0; i < s.size(); i++) {
        a[i] = {s[i], i};
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < a.size()-1; i++) {
        ans += abs(a[i+1].second - a[i].second);
    }

    cout << ans << endl;
}