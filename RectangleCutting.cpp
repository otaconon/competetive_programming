#include <bits/stdc++.h>

using namespace std;

int t;
int a, b;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;

    if (a % 2 == 0 && (a / 2 != b || b * 2 != a)) {
      cout << "Yes" << '\n';
    } 
    else if (b % 2 == 0 && (b / 2 != a || a * 2 != b)) {
      cout << "Yes" << '\n';
    }
    else {
      cout << "No" << '\n';
    }
  }
}