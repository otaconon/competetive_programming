#include <bits/stdc++.h>

using namespace std;

int max_segment() {
    
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    int total_c = 0;
    for (auto& x : a) {
        cin >> x;
        total_c += x == c ? 1 : 0;
    }
    
    int m = *max_element(a.begin(), a.end());

    int current_c = 0;
    int ans = total_c;
    vector<int> dp(m+1);
    for (int i = 0; i < n; i++) {
        if (a[i] == c) {
            current_c++;
            continue;
        }

        dp[a[i]] = max(dp[a[i]] + 1, current_c + 1);
        int c_suffix = total_c - current_c;
        ans = max(dp[a[i]] + c_suffix, ans);
    }

    cout << ans << endl;
}