#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> c(pow(3, n), string(pow(3, n), '#'));
    for (int i = n; i >= 1; i--) {
        int p = pow(3, i-1);
        for (size_t j = p; j < c.size(); j+=p*3)
            for (size_t k = p; k < c[j].size(); k+=p*3)
                for (int x = j; x < j+p; x++)
                    for (int y = k; y < k+p; y++)
                        c[x][y] = '.';
    }

    for (auto& s : c) {
        for (auto& ch : s) {
            cout << ch;
        }
        cout << endl;
    }
}