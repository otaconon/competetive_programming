#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<int> pq;
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            pq.push(-x);
            
            while (!pq.empty() && -pq.top() < sum + pq.top()) {
                pq.pop();
            }
            if (!pq.empty() && -pq.top() == sum + pq.top()) {
                ans++;
            }
        }

        cout << ans << std::endl;
    }
}