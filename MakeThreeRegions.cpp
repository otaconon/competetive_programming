#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string grid[2];
        cin >> grid[0];
        cin >> grid[1];

        int ans = 0;

        for (int j = 0; j < 2; j++) {
            for (int i = 1; i < n-1; i++) {
                if (grid[j][i] != '.')
                    continue;

                if ((grid[!j][i-1] == 'x' && grid[!j][i+1] == 'x') && (grid[j][i-1] == '.' && grid[j][i+1] == '.' && grid[!j][i] == '.')) {
                    ans++;
                }
            }
        }
        
        cout << ans << endl;
    }
}