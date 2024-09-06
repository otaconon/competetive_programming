#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int>& vec) {
    for (auto& x: vec) {
        cout << x << ' ';
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> odds;
    bool appeared = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (std::count(a.begin(), a.end(), -1) == n) {
        for (int i = 0; i < n; i++) {
            a[i] = i % 2 + 1;
        }
        print_vector(a);
        return;
    }

    for (int i = 0, j = -1; i <= n; i++) {
        if (i != n && a[i] == -1)
            continue;

        if (j == -1) {
            for (int k = i-1; k >= 0; k--) {
                a[k] = a[k+1] == 1 ? 2 : a[k+1] / 2; 
            }
        }
        else if (i == n) {
            for (int k = j+1; k < n; k++) {
                a[k] = a[k-1] == 1 ? 2 : a[k-1] / 2; 
            }
        }
        else {
            int l = j, r = i;
            while (l + 1 < r) {
                if (a[l] > a[r]) {
                    a[l+1] = a[l] == 1 ? 2 : a[l] / 2;
                    l++;
                }
                else {
                    a[r-1] = a[r] == 1 ? 2 : a[r] / 2;
                    r--;
                }
            }
            if (a[l] != a[r] / 2 && a[r] != a[l] / 2) {
                cout << -1 << "\n";
                return;
            }
        }

        j = i;
    }
    
    print_vector(a);
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}