#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;

        string rev = n;
        int cnt = 0;
        
        reverse(rev.begin(), rev.end());
        while (n != rev) {
            cnt++;
            n = to_string(stoi(n) + stoi(rev));
            rev = n;
            reverse(rev.begin(), rev.end());
        }
        
        cout << n << ' ' << cnt << endl;
    }
}