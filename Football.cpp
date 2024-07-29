#include <iostream>
#include <string>
using namespace std;
int main() {
    string characters;
    cin >> characters;
    int dlugosc = 1;
    for (int i = 1; i < characters.size();i++) {
        if (characters[i-1] == characters[i]) {
            dlugosc++;
        }
        if (characters[i - 1] != characters[i] || i == characters.size()-1) {
            if (dlugosc >= 7) {
                cout << "YES";
                return 0;
            }
            dlugosc = 1;
        }
    }

    cout << "NO" << endl;
}