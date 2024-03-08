#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (long long i = 1; i <= n; i++) {
        long long twos, threes, fours, sixs, eights;
        if (i == 1) {
            cout << 0 << '\n';
        }
        else if (i == 2) {
            cout << 6 << '\n';
        }
        else if (i == 3) {
            cout << 28 << '\n';
        }
        else if (i == 4) {
            cout << 96 << '\n';
        }
        else {
            twos = 4, threes = 8, fours = 4 + 4*(i-4), sixs = 4*(i-4), eights = (i-4)*(i-4);
            long long res = (i * i * i * i - (twos * 2 + threes * 3 + fours * 4 + sixs * 6 + eights * 8) - i*i)/2;
            cout << res << '\n';
        }
    }
}