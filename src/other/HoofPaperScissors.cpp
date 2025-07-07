#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("hps");

    // which gesture beats which gesture in order
    vector<char> gesture_beats = {'S', 'H', 'P'};

    int n, k;
    cin >> n >> k;
    vector<char> gestures(n);
    for (auto& x : gestures)
        cin >> x;

    // Check what are the wins for the first round depending on move bessie makes
    vector<int> first_gesture(3);
    for (int j = 0; j < 3; j++) {
        if (gesture_beats[j] == gestures[0])
            first_gesture[j] = 1;
    }
    
    // Create a dp[i][j][m] - maximum number of wins bessie can get using i swaps after j rounds if the gesture she uses is g
    // We however dont actaully need all the i states, we only need the previous one so lets create a separate vector prev
    vector<vector<int>> dp(n, vector<int>(3));
    vector<vector<int>> prev(n, vector<int>(3));
    for (int i = 0; i <= k; i++) {
        dp[0] = first_gesture;
        for (int j = 1; j < n; j++) {
            for (int g = 0; g < 3; g++) {
                // Calculate if we gain anything swapping to this gesture
                int gain = gesture_beats[g] == gestures[j] ? 1 : 0;
                dp[j][g] = dp[j-1][g] + gain;

                if (i == 0)
                    continue;
                
                // Check how much at most wins can we have if we swap to gesture g at the j-th round
                dp[j][g] = max(dp[j][g], max(prev[j-1][g], max(prev[j-1][(g+2)%3], prev[j-1][(g+1)%3])) + gain);
            }
        }
        prev = dp;
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
}