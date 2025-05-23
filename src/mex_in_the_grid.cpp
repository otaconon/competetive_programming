#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> a(n, vector<int>(n));
        int cnt = n*n-1;
        for (int i = 0; i < n/2; i++) {
            for (int j = i; j < n-i; j++)
                a[i][j] = cnt--;
            
            for (int j = i+1; j < n-i; j++)
                a[j][n-i-1] = cnt--;

            for (int j = n-i-2; j >= i; j--)
                a[n-i-1][j] = cnt--;

            for (int j = n-i-2; j > i; j--)
                a[j][i] = cnt--;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
}