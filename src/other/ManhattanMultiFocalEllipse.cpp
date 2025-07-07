#include <bits/stdc++.h>

using namespace std;

constexpr int M = 2 * 1e6;

long long n, d;

int getInd(int i)
{
	return i + M;
}

vector<long long> findSum(vector<long long>& v)
{
	sort(v.begin(), v.end());

	vector<long long> s(2*M+1);
	s[getInd(-M)] = std::accumulate(v.begin(), v.end(), 0LL) + n * M;
	int j = 0;
	for (int i = -M + 1; i < M + 1; i++)
	{
		while (j < n && i > v[j])
		{
			j++;
		}

		s[getInd(i)] = s[getInd(i - 1)] + 2LL * j - n;
	}

	return s;
}

int main()
{
	cin >> n >> d;
	vector<long long> x(n);
	vector<long long> y(n);

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	auto xSum = findSum(x);
	auto ySum = findSum(y);

	sort(xSum.begin(), xSum.end());
	sort(ySum.begin(), ySum.end());

	long long ans = 0;
	int j = 0;
	for (int i = 2 * M; i >= 0; i--)
	{
		while (j < 2 * M + 1 && xSum[i] + ySum[j] <= d)
		{
			j++;
		}

		ans += j;
	}

	cout << ans << endl;
}