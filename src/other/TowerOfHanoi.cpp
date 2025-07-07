#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    cout << fromRod << ' ' << toRod << '\n';
    towerOfHanoi(n-1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';
    towerOfHanoi(n, '1', '3', '2');
}