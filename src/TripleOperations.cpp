#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    map<long long, int> powers;
    int power = 1;
    powers[1] = 0;
    for (int i = 1; i <= 13; i++)
    {
        powers[power * 3] = i;
        power *= 3;
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        pair<long long, int> lp, rp;
        bool bl = false, br = false;
        for (auto [n, p] : powers)
        {
            if (n >= l && !bl)
            {
                lp = { n, p };
                bl = true;
            }
            if (n >= r && !br)
            {
                rp = { n, p };
                br = true;
            }
        }

        long long ans = (lp.second + 1) * 2;
        if (lp.second == rp.second)
        {
            ans += (r - l) * (lp.second + 1);
        }
        else
        {
            int sum = 0;
            for (auto [n, p] : powers)
            {
                if (p >= lp.second && p < rp.second)
                {
                    ans += (n*3 - sum) * (p + 1);
                }
                sum += n;
            }
            ans += (lp.first - l) * (lp.second + 1);
            ans += (r - ((rp.first+1)/3)) * (rp.second + 1);
        }

        cout << ans << endl;
    }
}