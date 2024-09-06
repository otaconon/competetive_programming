#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	cin >> S;
	int y = 0;
	int x = 0;
	int m = 0;
	int n = 0;
	int p = 0;
	int z = 0;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == 'B')
		{
			if (y == 0)
				y = i + 1;
			else
				x = i + 1;
		}

		if (S[i] == 'R')
		{
			if (m == 0)
				m = i + 1;
			else
				n = i + 1;
		}

		if (S[i] == 'K')
			p = i + 1;
	}
	if ((y % 2 == x % 2) || !(m < p && p < n))
		cout << "No";
	else
		cout << "Yes";
        
	return 0;
}