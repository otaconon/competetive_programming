#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (auto& x : s)
        if (x - 97 < 0)
            cnt++;

    transform(s.begin(), s.end(), s.begin(), cnt > s.size() / 2 ? ::toupper : ::tolower);

    cout << s << endl;
}