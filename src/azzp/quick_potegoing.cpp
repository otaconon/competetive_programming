#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    cout << binpow(a, b, 10) << '\n';
  }
}