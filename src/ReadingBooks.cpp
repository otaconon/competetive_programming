#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int ai = 0, bi = t.size()-1;
    long long aTime = t[ai], bTime = t[bi];

    if (n == 1) {
        cout << t[0]*2 << '\n';
        return 0;
    }

    pair<int, int> leftToRead;
    while (ai < t.size()-1 || bi > 0) {
        if (ai < t.size()-1 && aTime <= bTime) {
            ai++;
            if (ai == bi) {
                leftToRead = {0, t[ai]};
                ai++;

                if (ai >= t.size()) {
                    leftToRead.second += bTime - aTime;
                    continue;
                }
            }

            if (ai < t.size()) {
                aTime += t[ai];
            }
        }
        else if (bi >= 0) {
            bi--;
            if (ai == bi) {
                leftToRead = {1, t[bi]};
                bi--;

                if (bi < 0) {
                    leftToRead.second += aTime - bTime;
                    continue;
                }
            }

            if (bi >= 0) {
                bTime += t[bi];
            }
        }
    }

    if (leftToRead.first == 0) {
        aTime += leftToRead.second;
    }
    else {
        bTime += leftToRead.second;
    }

    cout << max(aTime, bTime) << '\n';
}