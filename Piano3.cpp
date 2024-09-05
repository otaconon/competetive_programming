#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> s[i];
    }

    vector<int> r, l;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            r.push_back(a[i]);
        }
        else {
            l.push_back(a[i]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < int(r.size())-1; i++) {
        ans += abs(r[i+1] - r[i]);
    }
    for (int i = 0; i < int(l.size())-1; i++) {
        ans += abs(l[i+1] - l[i]);
    }

    cout << ans << endl;
 }