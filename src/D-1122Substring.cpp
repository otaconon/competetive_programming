#include <bits/stdc++.h>

using namespace std;


int solve(vector<int>& a, int parity) {
  int n = a.size();
  set<int> p;
  int ans = 0;
  int l = parity; 
  for (int r = parity; r < (n+1)/2; r++) {
    if (a[2*r - parity] != a[2*r + !parity]) {
      while (l < r) {
        p.erase(a[2*l]);
        l++;
      }
      l++;
    }
    else if (p.count(a[2*r])){
      while (p.count(a[2*r])) {
        p.erase(a[2*l]);
        l++;
      }
    }

    if (a[2*r - parity] == a[2*r + !parity])
      p.insert(a[2*r]);
    
    ans = max(ans, 2 * (r - l + 1));
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int ans = max(solve(a, 0), solve(a, 1));

  cout << ans << endl;
}