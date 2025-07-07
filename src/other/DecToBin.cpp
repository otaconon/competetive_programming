#include <iostream>
#include <math.h>

void DecToBin()
{
	long long dec;
	long long bin = 0;
	std::cin >> dec;

	for (int i = 0; dec > 0; i++)
	{
		bin += dec % 2 == 1 ? pow(10, i) : 0;
		dec /= 2;
	}

	std::cout << bin;
}

int main()
{
	DecToBin();
}