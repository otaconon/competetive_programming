#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int M = to_string(n).size();
        N = n;
        K = k;
        
        return search(0, 0);
    }

    int search(long long x, long long order) {
        if (order == K)
            return x / 10;

        for (long long i = max(1LL, x); i <= x + 10; i++) {
            long long cnt = count_children(i, i+1);
            if (cnt >= K)
                return search(i * 10, order+1);
            order += cnt;
       }
       return -1;
    }

    int count_children(long long curr, long long next) {
        if (next > N) {
            if (curr > N)
                return 0;
            return N - curr + 1; 
        }
        return (next-curr) + count_children(curr * 10, next * 10);
    }
private:
    int N, M, K;
};

int main() {

}