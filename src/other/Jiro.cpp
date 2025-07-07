#include <bits/stdc++.h>

using namespace std;

int main() {
    char ab, ac, bc;
    cin >> ab >> ac >> bc;

    if ((ab == '>' && ac == '<') || (ab == '<' && ac == '>')) {
        cout << 'A' << endl;
    }
    if ((ab == '>' && bc == '>') || (ab == '<' && bc == '<')) {
        cout << 'B' << endl;
    }
    if ((ac == '>' && bc == '<') || (ac == '<' && bc == '>')) {
        cout << 'C' << endl;
    }
}