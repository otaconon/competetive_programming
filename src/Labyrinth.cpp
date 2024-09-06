#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> grid;
pair<int, int> s, e;

vector<vector<int>> vis;
vector<vector<int>> dp;
bool is_path = false;

stack<char> path;
void backtrack(int row, int col, char move) {
    path.push(move);

    vector<tuple<int, int, int, char>> v;
    if (row > 0) v.emplace_back(dp[row-1][col], row - 1, col, 'D');
    if (row < n - 1) v.emplace_back(dp[row+1][col], row + 1, col, 'U');
    if (col > 0) v.emplace_back(dp[row][col-1], row, col - 1, 'R');
    if (col < m - 1) v.emplace_back(dp[row][col+1], row, col + 1, 'L');

    sort(v.begin(), v.end());

    if (grid[row][col] == 'A')
        return;

    backtrack(get<1>(v[0]), get<2>(v[0]), get<3>(v[0]));
}

int main()
{
	cin >> n >> m;
	grid.resize(n);
	vis.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m, INT_MAX));
	for (int i = 0; i < n; i++)
	{
		cin >> grid[i];
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 'A')
			{
				s = make_pair(i, j);
			}
			else if (grid[i][j] == 'B')
			{
				e = make_pair(i, j);
			}
		}
	}

	queue<tuple<int, int, int>> q;
	q.emplace(s.first, s.second, 0);
	vis[s.first][s.second] = true;
	while (!q.empty())
	{
		tuple<int, int, int> t = q.front();
		int row = get<0>(t), col = get<1>(t), depth = get<2>(t);
		q.pop();
        if (grid[row][col] == 'B')
            is_path = true;

		dp[row][col] = depth;

		if (row > 0 && !vis[row - 1][col] && grid[row - 1][col] != '#') {
			vis[row-1][col] = true;
			q.emplace(row - 1, col, depth + 1);
		} 
		if (row < n - 1 && !vis[row + 1][col] && grid[row + 1][col] != '#') {
			vis[row+1][col] = true;
			q.emplace(row + 1, col, depth + 1);
		} 
		if (col > 0 && !vis[row][col - 1] && grid[row][col - 1] != '#') {
			vis[row][col-1] = true;
			q.emplace(row, col - 1, depth + 1);
		} 
		if (col < m - 1 && !vis[row][col + 1] && grid[row][col + 1] != '#') {
			vis[row][col+1] = true;
			q.emplace(row, col + 1, depth + 1);
		} 
	}

	if (is_path)
	{
		backtrack(e.first, e.second, '0');

		cout << "YES" << endl;
        cout << path.size()-1 << endl;
        while (path.size() > 1) {
            cout << path.top();
            path.pop();
        }
	}
	else
	{
		cout << "NO" << endl;
	}
}