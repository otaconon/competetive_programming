#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> ans(n);
    stack<int> s;
    for (int i = n-1; i >= 0; i--) {
        ans[i] = s.size();

        while (!s.empty() && h[i] > s.top()) {
            s.pop();
        }

        s.push(h[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}