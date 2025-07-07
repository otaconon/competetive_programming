#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        map<int, set<int>> chipsX;
        map<int, set<int>> chipsY;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            chipsX[x].insert(y);
            chipsY[y].insert(x);
        }

        int player[2] = {0, 0};
        int round = -1;

        int firstX = 1, lastX = a, firstY = 1, lastY = b;
        for (int j = 0; j < m; j++) {
            round++;
            char move;
            int k;
            cin >> move >> k;
            if (move == 'D') {
                lastX -= k;
                auto xptr = chipsX.upper_bound(lastX);
                if (xptr == chipsX.end())
                    continue;

                vector<int> to_erase;
                while (xptr != chipsX.end()) {
                    to_erase.push_back(xptr->first);
                    xptr++;
                }
                for (auto val : to_erase) {
                    for (auto y : chipsX[val]) {
                        chipsY[y].erase(val);
                        player[round % 2]++;
                    }
                    chipsX.erase(val);
                }
            }
            if (move == 'U') {
                firstX += k;
                auto xptr = chipsX.lower_bound(firstX);
                if (xptr == chipsX.begin())
                    continue;

                xptr--;

                vector<int> to_erase;
                while (xptr != chipsX.begin()) {
                    to_erase.push_back(xptr->first);
                    xptr--;
                }

                to_erase.push_back(xptr->first);
                for (auto val : to_erase) {
                    for (auto y : chipsX[val]) {
                        chipsY[y].erase(val);
                        player[round % 2]++;
                    }
                    chipsX.erase(val);
                }
            }
            
            if (move == 'R') {
                lastY -= k;
                auto yptr = chipsY.upper_bound(lastY);
                if (yptr == chipsY.end())
                    continue;

                vector<int> to_erase;
                while (yptr != chipsY.end()) {
                    to_erase.push_back(yptr->first);
                    yptr++;
                }
                for (auto val : to_erase) {
                    for (auto x : chipsY[val]) {
                        chipsX[x].erase(val);
                        player[round % 2]++;
                    }
                    chipsY.erase(val);
                }
            }

            if (move == 'L') {
                firstY += k;
                auto yptr = chipsY.lower_bound(firstY);
                if (yptr == chipsY.begin())
                    continue;

                yptr--;
                vector<int> to_erase;
                while (yptr != chipsY.begin()) {
                    to_erase.push_back(yptr->first);
                    yptr--;
                }
                to_erase.push_back(yptr->first);

                for (auto val : to_erase) {
                    for (auto x : chipsY[val]) {
                        chipsX[x].erase(val);
                        player[round % 2]++;
                    }
                    chipsY.erase(val);
                }
            }
            //std::cout << player[0] << ' ' << player[1] << endl;
            
        }
        
        std::cout << player[0] << ' ' << player[1] << endl;
    }
}