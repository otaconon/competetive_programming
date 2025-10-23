#include <iostream>

using namespace std;

int n = 0, m = 0;

bool search(int r, int c, vector<vector<char>>& g) {
  if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == 'x') {
    return false;
  }

  if (g[r][c] == 'w') {
    return true;
  }

  g[r][c] = 'x';

  bool res = false;
  res = search(r + 1, c, g);
  res |= search(r, c+1, g);
  res |= search(r-1, c, g);
  res |= search(r, c-1, g);

  return res;
}

int main() {
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));
  int rs = -1, cs = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'o') {
        rs = i;
        cs = j;
      }
    }
  }

  cout << (search(rs, cs, g) ? "TAK\n" : "NIE\n");
}