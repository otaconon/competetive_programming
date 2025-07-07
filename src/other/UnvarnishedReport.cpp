#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    
    size_t min_length = min(a.size(), b.size());

    for (int i = 0; i < min_length; i++) {
        if (a[i] != b[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    if (a.size() != b.size()) {
        cout << min_length + 1 << endl;
        return 0;
    }

    cout << 0 << endl;
}