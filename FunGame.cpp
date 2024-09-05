#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int one_pos = -1;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1' && one_pos == -1)
                one_pos = i;
        }

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (b[i] == '1' && i < one_pos)
                ans = false;
        }

        if ((ans && one_pos != -1) || (a == b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}