#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, a;
    cin >> n >> t >> a;

    if (t > n/2 || n/2 < a) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}