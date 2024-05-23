#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;

// 入力
vector<long long> A;

// 盤面 (l, r) からスタートして、
// その状態で手番であるプレイヤー視点での相手との得点差の最大値を返す
long long dfs(int l, int r, vector<vector<long long>> &dp) {
    // メモ化済みならば、メモ化された値を返す
    if (dp[l][r] != -INF) return dp[l][r];
    
    // 終端条件
    if (l == r) return 0;
    
    // 打てる手をすべて試す
    long long res = -INF;
    res = max(res, -dfs(l+1, r, dp) + A[l]);  // 先頭を除去
    res = max(res, -dfs(l, r-1, dp) + A[r-1]);  // 末尾を除去
    
    // メモ化しながら答えを返す
    return dp[l][r] = res;
}

int main() {
    // 入力
    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    // メモ化再帰
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, -INF));
    long long ans = dfs(0, N, dp);
    cout << ans << endl;
}