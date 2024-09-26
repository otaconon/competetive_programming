#include <bits/stdc++.h>
#include <ranges>

using namespace std;

constexpr long long MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<string, long long> mp;
    string z;
    for (int i = 0; i < k-1; i++)
        z += 'C';
    mp[z] = 1;

    for (auto c : s) {
        map<string, long long> tmp;

        for (auto& [t, v] : mp) {
            if (c != 'B') {
                tmp[t + 'A'] = v;
            }
            if (c != 'A') {
                tmp[t + 'B'] = v;
            }
        }

        mp.clear();

        for (auto& [t, v] : tmp) {
            string x = t;
            reverse(x.begin(), x.end());
            if (t != x) {
                string new_s = t.substr(1, t.size() - 1);
                if (mp.count(new_s)) {
                    mp[new_s] += v;
                    mp[new_s] %= MOD;
                }
                else {
                    mp[new_s] = v;
                    mp[new_s] %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (auto& [t, v] : mp) {
        ans += v;
        ans %= MOD;
    }

    cout << ans << endl;
}