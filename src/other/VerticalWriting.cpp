#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    int max_l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_l = max(max_l, (int)a[i].size());
    }

    vector<string> b(max_l);
    for (int i = 0; i < max_l; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (a[j].size() <= i) {
                b[i] += '*';
            }
            else {
                b[i] += a[j][i];
            }
        }
    }

    for (int i = 0; i < max_l; i++) {
        for (int j = b[i].size()-1; j >= 0; j--) {
            if (b[i][j] != '*')
                break;
            b[i].pop_back();
        }
    }

    for (auto& x : b) {
        cout << x << endl;
    }
}