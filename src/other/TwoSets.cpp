#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long total = (1 + n)*n / 2;
    if (total % 2) {
        cout << "NO" << '\n';
        return 0;
    }

    long long sum1 = 0;
    long long sum2 = 0;
    vector<int> a;
    vector<int> b;
    for (long long i = n; i >= 1; i--) {
        if (sum1 + i <= total / 2) {
            sum1 += i;
            a.push_back(i); 
        }
        else {
            b.push_back(i);
        }
    }

    cout << "YES" << '\n';

    cout << a.size() << '\n';
    for (auto x : a) {
        cout << x << ' ';
    }

    cout << '\n' << b.size() << '\n';
    for (auto x : b) {
        cout << x << ' ';
    }
}