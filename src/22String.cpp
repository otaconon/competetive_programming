#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  bool ones = true;
  bool twos = true;
  for (int i = 1; i <= (n + 1)/2 - 1; i++) {
    if (t[i-1] != '1') {
      ones = false;
      break;
    }
  }
  for (int i = (n + 1)/2 + 1; i <= n; i++) {
    if (t[i-1] != '2') {
      twos = false;
      break;
    }
  }

  if ((n % 2) && ones && twos && (t[(n+1)/2 - 1] == '/'))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}