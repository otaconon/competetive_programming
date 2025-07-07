#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    set<char> vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
    for (int i = 0; i < str.size(); i++) {
        str[i] = (char)tolower(str[i]);
        if (vowels.count(str[i]) == 0)
            cout << '.' << str[i];
    }
}