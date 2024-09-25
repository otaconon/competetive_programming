#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> can_be(n);
    for (int i = 0; i + k < s.size(); i++) {
        string left = "";
        string right = "";
        for (int j = i; j < i + k; j++) {
            if (j < i + k / 2) {
                left += s[j];
            }
            else if (j >= i + (k + 1) / 2) {
                right += s[j];
            }
        }
        reverse(right.begin(), right.end());

        bool palindrome = true;
        for (int j = 0; j < left.size(); j++) {
            if (left[j] != right[j] && left[j] != '?' && right[j] != '?') {
                palindrome = false;
                break;
            }
        }

        if (palindrome) {
            for (int j = 0; j < left.size(); j++) {
                if (left[j] == right[j] && right[j] == '?') {
                    can_be[j] = 1;
                }
                else if (left[j] == '?' || right[j] == '?') {
                    can_be[j] = 2;
                }
            }
        }
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (can_be[i]) {
            if (ans == 0) {
                ans = 1;
            }
            else {
                ans *= can_be[i];
            }
            cnt++;
        }
    }

    cout << pow(2, n) - pow(2, n - cnt) - ans << endl;
}