#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int p = 0;
        bool sign = x >= 0;
        x = abs(x);
        while (x >= 0) {
            int r = x % 10;
            
            res += r * pow(10, p);

            x /= 10;
        }
    }
};

int main() {

}