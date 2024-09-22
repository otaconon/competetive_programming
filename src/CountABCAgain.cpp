#include <bits/stdc++.h>

using namespace std;

bool check_c(char c) {
    if (c == 'A' || c == 'B' || c == 'C')
        return true;
    return false;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    string abc = "ABC";

    vector<bool> a(n);
    long long ans = 0;
    for (int i = 2; i < n; i++) {
        if (s[i-2] == 'A' && s[i-1] == 'B' && s[i] == 'C')
            ans++;
    }
    
    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        x--;

        for (int i = max(x, 2), j = 0; i < n, j < 3; i++, j++) {
            if (s[i-2] == 'A' && s[i-1] == 'B' && s[i] == 'C')
                ans--;
        }

        s[x] = c;

        for (int i = max(x, 2), j = 0; i < n, j < 3; i++, j++) {
            if (s[i-2] == 'A' && s[i-1] == 'B' && s[i] == 'C')
                ans++;
        }
        
        cout << ans << endl;
    }
}