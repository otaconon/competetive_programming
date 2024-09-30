#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 998244353;

using ll = long long;

int main()
{
	long long n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for (auto& x : a) cin >> x;
	const ll rem = k - accumulate(a.begin(), a.end(), 0LL);

	if (n == m) {
		for (int i = 0; i < n; i++) cout << 0 << " \n"[i == n - 1];
		return 0;
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
    auto b = a;
	sort(b.begin(), b.end());

    vector<ll> pref(n+1);
    for (int i = 0; i < n; i++)
        pref[i+1] = pref[i] + b[i];

	vector<long long> ans(n, -1);
	for (int i = 0; i < n; i++)
	{
		ll l = -1, r = rem + 1;
		while (r - l > 1)
		{
			ll mid = (l + r) / 2;

			long long rid = lower_bound(b.begin(), b.end(), b[i] + mid + 1) - b.begin();
			long long lid = n - m - (i >= n - m ? 1 : 0);
			long long cnt = 0;

			if (rid > lid)
                cnt += (rid - lid) * (b[i] + mid + 1) - (pref[rid] - pref[lid]);

			if (lid <= i && i < rid)
				cnt--;
			else
				cnt += mid;

			if (cnt > rem)
				r = mid;
			else
				l = mid;
		}

		if (l == rem)
			ans[ord[i]] = -1;
		else
			ans[ord[i]] = r;
	}


	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}

}