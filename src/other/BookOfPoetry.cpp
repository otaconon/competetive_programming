#include <bits/stdc++.h>
using namespace std;

void subtask1() {
    int n, s;
    cin >> n >> s;
    vector<int> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    long long best = LLONG_MAX;
    vector<int> best_perm(n);

    do {
        long long forced = 0;
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            if (cnt == s - 1) {
                forced++;
                if (forced >= best) {
                    break;
                }
                cnt = 0;
            }
            cnt += lines[perm[i]] + 1; 
            cnt %= s;
        }

        if (forced < best) {
            best = forced;
            best_perm = perm;
        }

    } while (next_permutation(perm.begin(), perm.end()));

    cout << best << "\n";
    for (int i = 0; i < n; i++) {
        cout << best_perm[i] + 1 << " ";
    }
    cout << "\n";

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    subtask1(); 
}
