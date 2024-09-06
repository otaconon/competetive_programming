#include <bits/stdc++.h>

using namespace std;

void solve() {

    int t;
    cin >> t;
    while (t--) {
        long long r;
        cin >> r;

        long long y = r;
        long long cnt = 0;
        for (long long x = 0; x <= r; x++) {
            while (y*y + x*x >= (r+1)*(r+1)) {
                y--;
            }
            
            long long upper_bound = y;
            while (x*x + upper_bound*upper_bound >= r*r && upper_bound > 0) {
                cnt++;
                upper_bound--;
            }
        }

        cout << cnt*4 << endl;;
    }
}

int main() {
    solve();
}