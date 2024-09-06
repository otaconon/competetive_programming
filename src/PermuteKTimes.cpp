#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector<int> x, a;

vector<vector<int>> dp;

void solve() {
    for (int i = 0; i < n; i++) {
        dp[i][0] = x[i];
    }

    for (int i = 1; i < 60; i++) {
        for (int j = 0; j < n; j++) {
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        q[i] = i;
    }

    for (int l = 0; l < 60; l++) {
        if ((1LL << l) & k) {
            for (int i = 0; i < n; i++) {
                q[i] = dp[q[i]][l];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[q[i]] << ' ';
    }

    cout << endl;

}

int main() {
    cin >> n >> k;
    x.resize(n);
    a.resize(n);
    dp.resize(n, vector<int>(60));

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve();

}