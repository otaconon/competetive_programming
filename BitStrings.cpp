#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long val = 1;
    for (int i = 0; i < n; i++) {
        val *= 2;
        val %= (1000000007);
    }

    cout << val << '\n';
}