#include <bits/stdc++.h>

using namespace std;

int main() {
    long long xs, ys;
    long long xt, yt;
    cin >> xs >> ys >> xt >> yt;

    if (xt < xs) {
        long long verti = abs(yt - ys);
        long long hori = (xs + ys) % 2 == 0 ? max(abs(xt - xs) - verti, 0LL) : max(abs(xt - xs) - 1 - verti, 0LL);
        hori = (hori + 1) / 2;
        long long ans = verti + hori;
        cout << ans << endl;
    }
    else {
        long long verti = abs(yt - ys);
        long long hori = (xs + ys) % 2 ? max(abs(xt - xs) - verti, 0LL) : max(abs(xt - xs) - 1 - verti, 0LL);
        hori = (hori + 1) / 2;
        long long ans = verti + hori;
        cout << ans << endl;
    }
}