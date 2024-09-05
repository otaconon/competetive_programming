#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
vector<int> r;
int n, k;

void solve(int x) {
    if (x == n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += ans[i];
        }

        if (s % k == 0) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= r[x]; i++) {
        ans[x] = i;
        solve(x+1);
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k;
    r.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    solve(0);
}