#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<char> b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
    }

    vector<int> f(n, -1);
    vector<std::string> ans(m, "No");
    for (int i = 0; i < m; i++) {
        if (b[i] == 'M' && f[a[i]] == -1) {
            f[a[i]] = i;
            ans[i] = "Yes";
        }
            
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}