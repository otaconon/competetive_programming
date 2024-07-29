#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> forces(3);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int force;
            cin >> force;
            forces[j] += force;
        }
    }

    cout << (all_of(forces.begin(), forces.end(), [](int i) {return i == 0;}) ? "YES" : "NO") << std::endl;
}