#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pesel;
        cin >> pesel;
        int ans = 1;

        int divisor = 1;

        if (pesel[10] == '?') {
            ans *= pesel[6] == '?' ? 10 : 1;
            ans *= pesel[7] == '?' ? 10 : 1;
            ans *= pesel[8] == '?' ? 10 : 1;
            ans *= pesel[9] == '?' ? 5 : 1;

            cout << ans / divisor << endl;
        }
        else {
            if (pesel[9] == '?')
            divisor = 5;

            for (int i = 6; i < 9; i++) {
                if (pesel[i] == '?')
                    divisor = 10;
            }

            ans *= pesel[6] == '?' ? 10 : 1;
            ans *= pesel[7] == '?' ? 10 : 1;
            ans *= pesel[8] == '?' ? 10 : 1;
            ans *= pesel[9] == '?' ? 5 : 1;

            cout << ans / divisor << endl;
        }

        
    }
}