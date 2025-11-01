#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> r(n, 0);

  cin >> r[0];
  for (int i = 1; i < n; i++) {
    cin >> r[i];
    r[i] = min(r[i], r[i-1]);
  }

  int d = n;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    while (d>0 && r[d-1]<x) d--;
    d--;
  }

  cout << max(0, d + 1) << '\n';
  return 0;
}

