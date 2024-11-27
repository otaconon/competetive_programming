#include "bits/stdc++.h"

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int block_idx = 0;
  char prev_c = ' ';
  int zero_idx = 0;
  for (int i = 0; i < s.size(); i++) {
    if (prev_c != '1' && s[i] == '1') {
      block_idx++;
    }

    prev_c = s[i];    

    if (block_idx == k-1 && s[i] == '0' && s[i-1] == '1') {
      zero_idx = i;
    }

    if (block_idx == k && s[i] == '1') {
      s[i] = s[zero_idx];
      s[zero_idx] = '1';
      zero_idx++;
    }
  }

  cout << s << endl;
}