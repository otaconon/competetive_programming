#include <bits/stdc++.h>
#include <ranges>

using namespace std;

void solve1() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    sort(a.rbegin(), a.rend());
    while (a[1] > 0) {
        a[0]--;
        a[1]--;
        sort(a.rbegin(), a.rend());
        ans++;
    }

    cout << ans << endl;
}

void solve2() {
    int n;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    int ans = 0;
    while (*ranges::next(a.begin(), 1) > 0) {
        sort(a.rbegin(), a.rend());
        ans++;
    }

    cout << ans << endl;
}

int main() {
    solve2();
}