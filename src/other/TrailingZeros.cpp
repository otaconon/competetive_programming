#include <bits/stdc++.h>

using namespace std;

void printFactorial(int x) {
    long long ans = 1;
    for (int i = 1; i <= x; i++) {
        ans *= i;
        cout << ans << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    long long val = n;
    long long ans = 0;
    while (val / 5) {
        val /= 5;
        ans += val;
    }
    cout << ans << '\n';
}