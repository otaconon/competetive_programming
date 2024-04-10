#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void mySoltion() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    map<int, int> valuesCount;
    ll ans = 0;
    ll l = 0, r = 0;
    ll lastR = -1;
    valuesCount[a[0]]++;
    while (r < n-1) {
        r++;
        valuesCount[a[r]]++;

        if (valuesCount.size() > k) {
            ans += ((r - l) * (r - l + 1)) / 2;
            if (lastR >= l) {
                ans -= ((lastR - l + 1) * (lastR - l + 2)) / 2;
            }
            
            lastR = r-1;
        }
        while (valuesCount.size() > k) {
            valuesCount[a[l]]--;
            if (valuesCount[a[l]] == 0) {
                valuesCount.erase(a[l]);
            }
            l++;
        }
    }

    ans += ((r - l + 1) * (r - l + 2)) / 2;
    if (lastR >= l) {
        ans -= ((lastR - l + 1) * (lastR - l + 2)) / 2;
    }

    cout << ans << '\n';
}

void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    ll ans = 0;
    int j = 0;
    map<int, int> occurances;
    for (int i = 0; i < n; i++) {
        while (j < n && (occurances.size() < k || occurances.count(values[j]) > 0)) {
            occurances[values[j]]++;
            j++;
        }

        ans += j - i;
        occurances[values[i]]--;
        if (occurances[values[i]] == 0) {
            occurances.erase(values[i]);
        }
    }

    cout << ans;
}

int main() {
    solution();
}