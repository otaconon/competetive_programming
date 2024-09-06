#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        vector<int> a(31);
        for (int i = 0; i < 30; i++) {
            if ((1 << i) & x) {
                if (a[i]) {
                    a[i+1] = 1;
                    a[i] = 0;
                }
                else if(i > 0) {
                    if (a[i-1] == 1) {
                        a[i+1] = 1;
                        a[i-1] = -1;
                    }
                    else {
                        a[i] = 1;
                    }
                }
                else if (i == 0) {
                    a[i] = 1;
                }
            }
            
        }

        cout << 31 << endl;
        for (int i = 0; i < 31; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}