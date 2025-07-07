#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 998244353;

bool check(int p, int k, vector<int>& vec) {
    if (vec[p] == 0)
        vec[p] = k;
    else if (k != vec[p])
        return false;
    
    return true;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> p(q), v(q), kind(q, 0);
    for (int i = 0; i < q; i++) {
        cin >> p[i];
        cin >> v[i];
    }

    for (int i = 0; i < q; i++) {
        for (int j = i+1; j < q; j++) {
            if (v[i] <= v[j]) {
                continue;
            }

            if (p[i] == p[j]) {
                cout << 0 << endl;
                return 0;
            }
            else if (p[i] < p[j]) {
                if (!check(i, -1, kind) || !check(j, 1, kind)) {
                    cout << 0 << endl;
                    return 0;
                }
            }
            else if (p[i] > p[j]) {
                if (!check(i, 1, kind) || !check(j, -1, kind)) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    long long cnt = count(kind.begin(), kind.end(), 0);
    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
}