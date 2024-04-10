#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVector(vector<T> vec) {
    for (auto x : vec) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> values(n);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<long long> prefix(n+1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] = values[i-1] + prefix[i-1];

    multiset<long long> prefixesInRange;
    long long ans = LONG_LONG_MIN;
    
    // for (int r = 0; r < b-a; r++) {
    //     prefixesInRange.insert(prefix[r]);
    // }

    for (int l = 0, r = a, space = 0; r < b; r++, space++) {
        prefixesInRange.insert(prefix[space]);
        ans = max(ans, prefix[r] - *prefixesInRange.begin());
    }

    for (int l = 0, r = b, space = b-a; r <= n; l++, r++, space++) {
        prefixesInRange.insert(prefix[space]);
        ans = max(ans, prefix[r] - *prefixesInRange.begin());

        prefixesInRange.erase(prefixesInRange.find(prefix[l]));
    }

    //printVector(prefix);

    // prefixesInRange.clear();

    // for (int i = b-a; i < b; i++) {
    //     prefixesInRange.insert(prefix[i]);
    // }

    // for (int l = 0, r = b, space = b-a; r <= n; l++, r++, space++) {
    //     prefixesInRange.insert(prefix[r]);
    //     ans = max(ans, *prefixesInRange.rbegin() - prefix[l]);

    //     prefixesInRange.erase(prefixesInRange.find(prefix[space]));
    // }

    cout << ans << endl;
}