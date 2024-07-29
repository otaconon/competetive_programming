#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
    int suma = 0, n, licznik = 0;
    int one = 0, two = 0, three =0 , four =0;
    cin >> n;
    vector <int> tablica(n);
    for (int i = 0; i < n;i++) {
        cin >> tablica[i];
    }
    for (int i = 0; i < n;i++) {
        if (tablica[i] == 4) {
            four++;
        }
        if (tablica[i] == 3) {
            three++;
        }
        if (tablica[i] == 2) {
            two++;
        }
        if (tablica[i] == 1) {
            one++;
        }
    }
    suma += four;
    suma += two / 2;
    int pozostale_2 = two % 2;
    suma += one / 4;
    int pozostale_1 = one % 4;
    if (three > pozostale_1) {
        suma += three;
    }
    else {
        pozostale_1 -= three;
    }
    if (pozostale_2 > pozostale_1) {
        suma += pozostale_2;
    }
    else {
        pozostale_1 -= 2 * pozostale_2;
    }
    suma += pozostale_1/4;
    cout << suma;

}