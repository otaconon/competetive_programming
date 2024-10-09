#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

int main() {
    long long n;
    cin >> n;

    string s = "";
    string x = to_string(n);
    for (int i = 0; i < min(n, 11LL); i++) {
        s += x[i % x.size()];
    }
    long long i = s.size() * n % 18LL;
    string s_ans = "";
    for (int j = 0; j < s.size(); j++) {
        s_ans += s[(i + j) % s.size()];
    }

    cout << stoll(s_ans) % mod << endl;
}