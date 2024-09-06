#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("gates");

    int n;
	cin >> n;
	string s;
	cin >> s;

	set<pair<pair<int, int>, pair<int, int>>> visedge;
	set<pair<int, int>> visnode;
	int ans = 0;
	pair<int, int> prev{0, 0};
	visnode.insert(prev);

	for (int i = 0; i < n; i++) {
		int x = prev.first;
		int y = prev.second;
		if (s[i] == 'N') {
			x++;
		} else if (s[i] == 'S') {
			x--;
		} else if (s[i] == 'E') {
			y--;
		} else {
			y++;
		}

		// Check if the edge from prev to {x, y} was visited (see 2nd
		// observation)
		if (visedge.find({{x, y}, prev}) == visedge.end() &&
		    visnode.find({x, y}) != visnode.end()) {
			ans++;
		}

		visedge.insert({{x, y}, prev});
		visedge.insert({prev, {x, y}});
		visnode.insert({x, y});

		prev.first = x;
		prev.second = y;
	}
	cout << ans << "\n"; 
}