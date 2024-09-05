#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        string c = a;
        int ans = a.size() + b.size();
        for (int k = 0; k < b.size(); k++) {
            int cnt = 0;
            for (int i = 0, j = k; i < a.size() && k < b.size(); i++) {
                if (a[i] == b[j]) {
                    j++;
                    cnt++;
                }
            }
            ans = min(ans, (int)a.size() + (int)b.size() - cnt);
        }
        
        cout << ans << endl;
    }
}