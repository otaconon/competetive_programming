#include <bits/stdc++.h>

using namespace std;

/*
    We are supposed to answer queries finding the number of pairs where i < j and a[i] > a[j];
    After updating every a[j] > k to k, the badness of hair is decresed by some amount x;
    We want to find how many j's there are for every i such that a[j] > k and i < j and a[i] > a[j];

    This can be done with brute force by iterating for every i over the whole array updating values to k,
    Next count the badness by iterating over whole arary again counting badness. This takes O(N^3) time;

    Let's try answering queries for every i in O(N * log(N)) time. This can be done by using
    oreder set, when iterating over the array we add the values one by one to ordered set, and check the order of element,
    we then know that we need to add the number of elements greater than the current one in the set. This gives us total O(N^2 * log(N)) time;
*/

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int n) : n(n), bit(std::vector<long long>(n)) {}

    long long range_sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += bit[r];
        }
        return res;
    }

    void add(int idx) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += 1;
        }
    }

};

int main() {
    setIO("haircut");

    int n;
    cin >> n;
    FenwickTree t(n+2);
    vector<long long> ans(n+2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans[x+1] += t.range_sum(x+1, n+1);
        t.add(x);
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += ans[i];
        cout << total << endl; 
    }
    

}