#include <bits/stdc++.h>
#include <ranges>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    cin >> k;

    std:: cout << std::ranges::count_if(a, [k](auto&& x) { return k <= x; }) << '\n';
}