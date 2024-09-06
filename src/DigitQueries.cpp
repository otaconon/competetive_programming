#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int q;
    cin >> q;

    vector<ll> powers(19, 1);
    for (int i = 1; i < 19; i++) {
        powers[i] = powers[i-1] * 10;
    }

    while (q--) {
        long long k;
        cin >> k;

        int numberOfDigits = 0;
        long long digits = 0;
        long long prevDigits = 0;

        for (int i = 1; i < 19; i++) {
            digits += (powers[i] - powers[i-1]) * i;

            if (digits >= k) {
                numberOfDigits = i;
                break;
            }
            prevDigits = digits;
        }

        ll low = powers[numberOfDigits-1];
        ll high = powers[numberOfDigits] - 1;
        ll ans = 0;
        ll startAns = 0;
        while (low <= high) {
            ll mid = (high + low) / 2;
            ll startPos = (mid - powers[numberOfDigits - 1]) * numberOfDigits + prevDigits + 1;
            
            if (startPos <= k) {
                if (mid > ans) {
                    ans = mid;
                    startAns = startPos;
                }
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        string number = to_string(ans);
        cout << number[k - startAns] << endl;
    }
}

int main() {
    solve();
}