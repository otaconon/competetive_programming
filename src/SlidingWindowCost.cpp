#include <bits/stdc++.h>

using namespace std;

class Window
{
public:
	Window(vector<int>& values)
	{
		for (int value : values)
		{
			eraseQueue.push(value);
		}

		sort(values.begin(), values.end());

		for (size_t i = 0; i < values.size(); i++)
		{
			if (i < (values.size() + 1) / 2)
			{
				leftValues.insert(values[i]);
			}
			else
			{
				rightValues.insert(values[i]);
			}
		}

		int median = *leftValues.rbegin();

		long long cost = 0;
		for (long long x : leftValues)
			leftSum += x;

		for (long long x : rightValues)
			rightSum += x;
	}

	void ins(int newVal)
	{
		if (rightValues.find(eraseQueue.front()) != rightValues.end())
		{
			eraseRight(rightValues.lower_bound(eraseQueue.front()));

			if (newVal < *leftValues.rbegin())
			{
				insertLeft(newVal);
				insertRight(*leftValues.rbegin());
				eraseLeft(leftValues.find(*leftValues.rbegin()));
			}
			else
			{
				insertRight(newVal);
			}
		}
		else
		{
			eraseLeft(leftValues.lower_bound(eraseQueue.front()));

			if (leftValues.empty() && rightValues.empty())
			{
				insertLeft(newVal);
			}
			else if (leftValues.empty())
			{
				if (newVal < *rightValues.begin())
				{
					insertLeft(newVal);
				}
				else
				{
					insertLeft(*rightValues.begin());
					eraseRight(rightValues.begin());
					insertRight(newVal);
				}
			}
			else if (newVal <= *rightValues.begin())
			{
				insertLeft(newVal);
			}
			else
			{
				insertLeft(*rightValues.begin());
				eraseRight(rightValues.begin());
				insertRight(newVal);
			}
		}

		eraseQueue.pop();
		eraseQueue.push(newVal);
	}

	long long getCost()
	{
		int median = ((leftValues.size() + rightValues.size()) % 2) == 0 ? 0 : (*leftValues.rbegin());
		return rightSum - leftSum + median;
	}

	void printWindows()
	{
		cout << "LEFT: ";
		for (auto& x : leftValues)
		{
			cout << x << ' ';
		}

		cout << "   RIGHT: ";
		for (auto& x : rightValues)
		{
			cout << x << ' ';
		}
		cout << '\n';
	}

private:
	void eraseLeft(const multiset<int>::iterator value)
	{
		leftSum -= *value;
		leftValues.erase(value);
	}

	void eraseRight(const multiset<int>::iterator value)
	{
		rightSum -= *value;
		rightValues.erase(value);
	}

	void insertLeft(int value)
	{
		leftSum += value;
		leftValues.insert(value);
	}

	void insertRight(int value)
	{
		rightSum += value;
		rightValues.insert(value);
	}

	multiset<int> leftValues;
	multiset<int> rightValues;
	queue<int> eraseQueue;

	long long leftSum = 0;
	long long rightSum = 0;
};

void my_solution()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	vector<int> initVector(k);
	for (int i = 0; i < k; i++)
	{
		initVector[i] = a[i];
	}

	Window window(initVector);
	//window.printWindows();
	cout << window.getCost() << ' ';
	for (int i = k; i < n; i++)
	{
		window.ins(a[i]);
		cout << window.getCost() << ' ';
		//window.printWindows();
	}
}

int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	my_solution();
}