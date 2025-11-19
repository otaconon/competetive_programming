#include <vector>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<bool> cnt(1e6+5);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x] = !cnt[x];
  }

  bool odd = false;
  for (int i = 0; i < 1e6+5; i++) {
    if (odd == false && cnt[i]) {
      odd = true;
    }
    else if (odd == true && cnt[i]) {
      cout << "NIE\n";
      return 0;
    }
  }

  cout << "TAK\n";
}