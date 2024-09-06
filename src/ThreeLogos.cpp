#include <bits/stdc++.h>

using namespace std;

enum class Variation {
    Top,
    Bottom,
    Even
};

map<int, char> ch = {
    {0, 'A'}, {1, 'B'}, {2, 'C'}
};

void rotate(vector<vector<int>>& ads) {
    for (int i = 0; i < 3; i++) {
        swap(ads[i][0], ads[i][1]);
    }
}

void printBillboard(vector<vector<int>>& ads, Variation v, int id) {
    switch (v) {
        case Variation::Even: {
            if (ads[0][0] < ads[0][1]) {
                rotate(ads);
            }

            cout << ads[0][0] << endl;
            for (int i = 0; i < (ads[0][1] + ads[1][1] + ads[2][1]); i++) {
                for (int j = 0; j < ads[0][0]; j++) {
                    if (i < ads[0][1])
                        cout << 'A';
                    else if (i < (ads[0][1] + ads[1][1]))
                        cout << 'B';
                    else
                        cout << 'C';
                }
                cout << endl;
            }
            break;
        }
        case Variation::Top: {
            vector<int> other;
            for (int i = 0; i < 3; i++) {
                if (i != id) {
                    other.push_back(i);
                }
            }

            if (ads[id][0] < ads[id][1]) {
                rotate(ads);
            }

            cout << ads[id][0] << endl;
            for (int i = 0; i < (ads[id][1] + ads[other[0]][1]); i++) {
                for (int j = 0; j < ads[id][0]; j++) {
                    if (i < ads[id][1]) {
                        cout << ch[id];
                    }
                    else {
                        if (j < ads[other[0]][0]) {
                            cout << ch[other[0]];
                        }
                        else {
                            cout << ch[other[1]];
                        }
                    }
                }
                cout << endl;
            }
            break;
        }
    }
}

bool checkBillboard(vector<vector<int>> ads) {
    int w_sum = ads[0][0] + ads[1][0] + ads[2][0];
    int h_sum = ads[0][1] + ads[1][1] + ads[2][1];

    if ((ads[0][0] == ads[1][0] && ads[1][0] == ads[2][0] && ads[0][0] == h_sum) ||
        (ads[0][1] == ads[1][1] && ads[1][1] == ads[2][1] && ads[0][1] == w_sum)) {
        printBillboard(ads, Variation::Even, -1);
        return true;
    }

    for (int i = 0; i < 3; i++) {
        int w = w_sum - ads[i][0];
        int h1 = ads[(i+1)%3][1];
        int h2 = ads[(i+2)%3][1];
        int h = h_sum - h1;

        if (w == ads[i][0] && h == w && h1 == h2) {
            printBillboard(ads, Variation::Top, i);
            return true;
        }
    }

    // for (int i = 0; i < 3; i++) {
    //     int h = h_sum - ads[i][1];

    //     if (h == ads[i][1] && w_sum == h) {
    //         printBillboard(ads, Variation::Bottom, i);
    //         return true;
    //     }
    // }

    return false;
}

void solve(vector<vector<int>>& ads) {
    for (int i = 0; i < (1 << 3); i++)
    {
        vector<int> toSwap;
        for (int j = 0; j < 3; j++)
        {
            if (i & (1 << j))
            {
                toSwap.push_back(j);
            }
        }

        vector<vector<int>> adsCopy = ads;
        for (auto j : toSwap)
        {
            swap(adsCopy[j][0], adsCopy[j][1]);
        }

        if(checkBillboard(adsCopy)) {
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    vector<vector<int>> v(3, vector<int>(2));
    for (int i = 0; i < 3; i++)
        cin >> v[i][0] >> v[i][1];

    solve(v);
}