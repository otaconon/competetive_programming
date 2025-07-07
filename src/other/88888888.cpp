#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

using mint = atcoder::static_modint<998244353>;

int main() {
    long long n;
    cin >> n;

    long long x = n;
    mint r = 1;
    while (x) {
        x /= 10;
        r *= mint(10);
    } 

    mint ans = mint(n) * (mint(1) - r.pow(n)) * (mint(mint(1) - r).inv());
    cout << ans.val() << endl;
}