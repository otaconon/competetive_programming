#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

typedef long long ll;

int n;
vector<int> a;

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  ll res = 1;

  for (int i = 0; i < n && a[i] <= res; i++) {
    res = res + a[i];
  }

  cout << res << '\n';
}