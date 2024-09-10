#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    random_device rd;
    vector<int> a = {1, 2, 3, 4, 5, 6};
    shuffle(a.begin(), a.end(), rd);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }

    return 0;
}