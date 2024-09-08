#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    int elem = 0;
    for (int i = 0; i < n; i++) {
        int new_elem = -1;
        if (elem >= i) {
            new_elem = a[elem][i]-1;
        }
        else {
            new_elem = a[i][elem]-1;
        }
        elem = new_elem;
    }

    cout << elem + 1 << endl;

}