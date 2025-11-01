#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
vector<pair<int, int>> placed;

bool check(int r, int c) {
  for (auto& [rx, cx] : placed) {
    if (r == rx || c == cx) return false;
    if (r + c == rx + cx || r - c == rx - cx) return false;
  }
  return true;
}

void place_queen(int r, int c) {
  if (!check(r, c)) return;

  placed.push_back({r, c});
  if (r == n-1) {
    ans++;
  }
  else {
    for (int cx = 0; cx < n; cx++) {
      place_queen(r+1, cx);
    }
  }
  placed.pop_back();
}

int main() {
  cin >> n;

  for (int c = 0; c < n; c++) {
    place_queen(0, c);
  }

  cout << ans << '\n';
}