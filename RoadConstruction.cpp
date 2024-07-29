#include "bits/stdc++.h"

using namespace std;

class UnionFind {
public:
    UnionFind(vector<int> v) {
        tab = std::move(v);
        numOfComp = tab.size();
        numOfMem.resize(tab.size(), 1);
    }

    void unify(int a, int b) {
        while (b !=  tab[b]) {
            b = tab[b];
        }
        while (a != tab[a]) {
            a = tab[a];
        }

        if (a == b)
            return;

        numOfComp--;
        if (numOfMem[a] < numOfMem[b])
            swap(a, b);
        
        tab[b] = a;
        numOfMem[a] += numOfMem[b];
        mxMembers = max(mxMembers, numOfMem[a]);
        
    }

    int getNumOfMembers() {
        return mxMembers;
    }

    int getNumOfComp() {
        return numOfComp;
    }

private:
    vector<int> tab;
    vector<int> numOfMem;
    int mxMembers = 1;
    int numOfComp;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }

    UnionFind uf(v);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unify(a, b);
        cout << uf.getNumOfComp() << ' ' << uf.getNumOfMembers() << endl;
    }

}