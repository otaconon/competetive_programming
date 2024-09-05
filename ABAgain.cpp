#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = n % 10;
        int b = floor(n / 10);
        cout << a + b << endl;
    }
}