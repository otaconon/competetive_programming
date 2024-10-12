#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> right(26);
    for (int i = 0; i < s.size(); i++) {
        right[s[i] - 'A']++;
    }

    long long ans = 0;
    vector<int> left(26);
    for (int i = 0; i < s.size(); i++) {
        right[s[i] - 'A']--;
        for (int j = 0; j < 26; j++) {
            ans += right[j] * left[j];
        }
        left[s[i] - 'A']++;
    } 

    cout << ans << endl;
}