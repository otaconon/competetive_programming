#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
            

        k -= n;
        int cDiag = n-1;
        int ans = 1;
        
        while (k > 0) {
            k -= cDiag;
            ans++;
            if (k <= 0)
                break;
            k -= cDiag;
            ans++;
            cDiag--;
        }

        cout << ans << endl;
    }
}