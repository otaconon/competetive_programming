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

    vector<vector<int>> a(n, vector<int>(3));
    if (check_c(s[0])) {
        a[0][s[0] - 65]++;
    }
   
    for (int i = 1; i < n; i++) {
        a[i] = a[i-1];
        if (i >= 3) {
            if (check_c(s[i-3]))
                a[i][s[i-3] - 65]--;
        }

        if (check_c(s[i]))
            a[i][s[i] - 65]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == vector{1, 1, 1}) {
            ans++;
        }
    }
    
    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        x--;

        if (check_c(s[x])) {
            for (int i = 0,  j = x; i < 3 && j < n; i++, j++) {
                if (a[j] == vector{1, 1, 1}) {
                    ans--;
                }
                a[j][s[x] - 65]--;
            }
        }
            
        
        if (check_c(c)) {
            for (int i = 0, j = x; i < 3 && j < n; i++, j++) {
                a[j][c - 65]++;
                if (a[j] == vector{1, 1, 1}) {
                    ans++;
                }
            }
        }
        
        cout << ans << endl;
    }
}