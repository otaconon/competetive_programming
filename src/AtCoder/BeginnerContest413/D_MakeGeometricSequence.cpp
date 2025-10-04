#include <bits/stdc++.h>
#include <ranges>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    long long x = ranges::count(a, a[0]), y = ranges::count(a, -a[0]);
    if (x == n)
        return true;
    else if (x + y == n && abs(x - y) <= 1)
        return true;
    
    ranges::sort(a, {}, [](long long x) { return abs(x); });
    for (int i = 1; i < n; i++)
        if (a[i] * a[0] != a[i-1] * a[1])
            return false;
    
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "Yes" : "No") << '\n';
    }
}