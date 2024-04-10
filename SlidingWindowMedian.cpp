#include <bits/stdc++.h>
 
using namespace std;
 
class Window {
public:
	Window(int initialElement, size_t leftWindowSize, size_t rightWindowSize) : leftWindowSize(leftWindowSize), rightWindowSize(rightWindowSize) {
        left.insert(initialElement);
    }
 
	int GetMedian() {
		auto medianPtr = left.rbegin();
 
		return *medianPtr;
	}
 
	void Insert(int value) {
		int median = *left.rbegin();
		if (median < value) {
			right.insert(value);
			if (right.size() > rightWindowSize) {
				left.insert(*right.begin());
				right.erase(right.find(*right.begin()));
			}
		}
		else {
			left.insert(value);
 
			if (left.size() > leftWindowSize) {
				right.insert(*left.rbegin());
				left.erase(left.find(*left.rbegin()));
			}
		}
	}

    void Erase(long val) {
        if (right.find(val) != right.end())
            right.erase(right.find(val));
        else
            left.erase(left.find(val));

        if (left.empty()) {
            left.insert(*right.begin());
            right.erase(right.find(*right.begin()));
	}
}

    void PrintWindow() {
        cout << "LEFT: ";
        for (auto& x : left) {
            cout << x << ' ';
        }
        cout << "RIGHT: ";
        for (auto& x : right) {
            cout << x << ' ';
        }
        cout << endl;
    }
 
private:
	multiset<int> left;
	multiset<int> right;
	int rightWindowSize;
	int leftWindowSize;
};
 
int main() {
	int n;
	size_t k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    
	Window win(a[0], (k + 1) / 2, k / 2);
    for (int i = 1; i < k; i++) {
        win.Insert(a[i]);
    }

    //win.PrintWindow();
    cout << win.GetMedian() << ' ';
	for (int i = k; i < n; i++) {
        if (k == 1) {
            win.Insert(a[i]);
            win.Erase(a[i-k]);
        }
        else {
            win.Erase(a[i - k]);
		    win.Insert(a[i]);
        }
        cout << win.GetMedian() << ' ';
	}

    cout << '\n';
}