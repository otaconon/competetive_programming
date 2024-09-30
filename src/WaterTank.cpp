#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }

    sort(h.rbegin(), h.rend());

    set<pair<ll, ll>, greater<pair<int, int>>> s;
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
        auto it = s.upper_bound({h[i].second, h[i].first});
        if (it != s.end())
            ans[h[i].second] = h[i].first * (h[i].second - it->first) + ans[it->first];
        else
            ans[h[i].second] = h[i].first * (h[i].second+1) + 1;
        
        s.insert({h[i].second, h[i].first});
    }

    for (auto& x : ans) {
        cout << x << ' ';
    }
}