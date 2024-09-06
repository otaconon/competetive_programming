#include <bits/stdc++.h>

using namespace std;

void solve_greedy() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(2, vector<int>(n+m+1));
    vector<int> p, t;
    for (int i = 0; i < n + m + 1; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n+m+1; i++) {
        cin >> a[1][i];
    }

    int bad = -1;
    int badType = -1;
    long long ans = 0;
    vector<int> types(n+m+1);
    int bounds[2] = {n, m};
    int cur[2] = {0, 0};

    for (int i = 0; i < n+m; i++) {
        int curType = 0;
        if (a[0][i] < a[1][i]) {
            curType = 1;
        }

        if (cur[curType] == bounds[curType]) {
            curType = 1 - curType;
            if (bad == -1) {
                bad = i;
                badType = 1 - curType;
            }
        }

        types[i] = curType;
        ans += a[types[i]][i];
        cur[types[i]] += 1;
    }

    for (int i = 0; i < n+m; i++) {
        long long val = ans - a[types[i]][i];
        if (bad != -1 && i < bad && types[i] == badType) {
            val = val + a[badType][bad] - a[1 - badType][bad] + a[1 - badType][n+m];
        }
        else {
            val = val + a[types[i]][n+m];
        }

        cout << val << ' ';
    }
    cout << ans << endl;
}

void solve_dp() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+m+1), b(m+m+1);
    for (int i = 0; i < n+m+1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n+m+1; i++) {
        cin >> b[i];
    }

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        
    }
}