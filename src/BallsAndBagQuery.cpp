#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<int> s;
    set<int> f;
    while (q--) {
        int y;
        cin >> y;
        if (y == 1) {
            int x;
            cin >> x;
            s.insert(x);
            f.insert(x);
        }
        else if (y == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x));
            if (s.find(x) == s.end()) {
                f.erase(x);
            }
        }
        else {
            cout << f.size() << endl;
        }
    }
}