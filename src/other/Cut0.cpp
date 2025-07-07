#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;   
    int stop = x.size();
    for (int i = x.size()-1; i >= 0; i--) {
        if (x[i] == '0') {
            stop = i;
        }
        else if (x[i] == '.') {
            stop = i;
            break;
        }
        else {
            break;
        }
    }

    for (int i = 0; i < stop; i++) {
        cout << x[i];
    }
}