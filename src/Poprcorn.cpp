#include <bits/stdc++.h>

using namespace std;

bool allOnesInRange(const std::bitset<10>& bits, int x, int y) {
    for (int i = x; i <= y; ++i) {
        if (!bits[i])
            return false;
    }
    return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<bitset<10>> masks(n);
	for (auto& x : masks) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
			x[i] = s[i] == 'o' ? 1 : 0;
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);

	int best = INT_MAX;
	do {
		bitset<10> mask;
		for (int i = 0; i < n; i++) {
			mask |= masks[ord[i]];
			if (allOnesInRange(mask, 0, m-1)) {
				best = min(best, i + 1);
				break;
			}
		}
	} while (next_permutation(ord.begin(), ord.end()));

    cout << best << endl;
}