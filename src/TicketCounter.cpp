#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> ans(n);
    ans[0] = t[0] + a;
    for (int i = 1; i < n; i++) {
        ans[i] = t[i] - ans[i-1] > 0 ? t[i] + a : ans[i-1] + a;
    }

    for (auto& x : ans)
        cout << x << endl;
}