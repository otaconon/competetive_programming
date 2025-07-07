#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int first;
    cin >> first;
    vector<int> builds(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> builds[i];
    }

    for (int i = 0; i < n-1; i++) {
        if (builds[i] > first) {
            cout << i + 2 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}