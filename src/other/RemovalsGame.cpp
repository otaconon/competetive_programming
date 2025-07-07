#include <bits/stdc++.h>

using namespace std;

string solve(deque<int>& a, deque<int>& b) {
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        auto c = b;
        reverse(c.begin(), c.end());
        if (a == b || a == c) {
            cout << "Bob" << endl;
        }
        else {
            cout << "Alice" << endl;
        }

        
    }
}