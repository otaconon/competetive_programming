#include "bits/stdc++.h"

using namespace std;

int main() {
  vector<int> a(10);
  int n;
  cin >> n;
  string x = to_string(n);
  for (int i = 0; i < 6; i++) {
    a[x[i] - '0']++;
  }
  if (a[1] == 1 && a[2] == 2 && a[3] == 3) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}