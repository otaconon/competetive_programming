#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        int ones_cnt = 0;
        int zeros_cnt = 0;

        if (a[0] == '1')
            ones_cnt++;
        else
            zeros_cnt++;

        for (int i = 1; i < n; i++) {
            if (a[i] == '1')
                ones_cnt++;
            else if (a[i-1] != '0'){
                zeros_cnt++;
            }
        }

        if (ones_cnt > zeros_cnt)
            cout << "Yes" << endl;
        else {
            cout << "No" << endl;
        }
    }
}