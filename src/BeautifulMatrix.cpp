#include <bits/stdc++.h>

using namespace std;

struct vec2{
    int x, y;
};

int main() {
    vec2 one_position = {-1, -1};  
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            int a;
            cin >> a;
            if (a == 1) {
                one_position = {x, y};
            }
        }
    }

    int answer = abs(one_position.x - 2) + abs(one_position.y - 2); 

    cout << answer << endl;
}