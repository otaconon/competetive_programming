#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
    cin >> s;
	vector<int> R, B, K;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'R')
			R.push_back(i);

		if (s[i] == 'B')
			B.push_back(i);

		if (s[i] == 'K')
			K.push_back(i);
	}

	if (B[0] % 2 != B[1] % 2) {
        if (R[0] < K[0] && K[0] < R[1])
            cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
        
}