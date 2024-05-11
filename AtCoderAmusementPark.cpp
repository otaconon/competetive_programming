#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    int empty = k;
    int cnt = 1;
    while (!q.empty()) {
        if (q.front() > empty) {
            empty = k;
            cnt++;
        }
        else {
            empty -= q.front();
            q.pop();
        }
    }

    cout << cnt << endl;
}