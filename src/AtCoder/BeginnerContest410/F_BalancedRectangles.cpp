#include <bits/stdc++.h>

using namespace std;

vector<string> flip(vector<string>& v) {
    int h = v.size(), w = v[0].size();
    vector<string> res(w);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            res[i].push_back(v[j][i]);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<string> a(h);
        for (int i = 0; i < h; i++)
            cin >> a[i];

        if (h > w)
            a = flip(a);

        h = a.size();
        w = a[0].size();

        long long ans = 0;
        int ofs = h*w;
        vector<int> bk(ofs*2+1);
        for (int i = 0; i < h; i++) {
            vector<int> cnt(w);
            for (int j = i; j < h; j++) {
                for (int k = 0; k < w; k++) {
                    cnt[k] += a[j][k] == '#' ? 1 : -1;
                }

                int acc = 0;
                bk[acc+ofs]++;
                for (int k = 0; k < w; k++) {
                    acc += cnt[k];
                    ans += bk[acc+ofs];
                    bk[acc+ofs]++;
                }

                acc = 0;
                bk[acc+ofs] = 0;
                for (int k = 0; k < w; k++) {
                    acc += cnt[k];
                    bk[acc+ofs] = 0;
                }
            }
        }

        cout << ans << '\n';
    }
}