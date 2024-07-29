#include "bits/stdc++.h"
#include <cstdlib>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

class UnionFind {
public:
    UnionFind(int sz) {
        tab.resize(sz);
        h.resize(sz, 1);
        for (int i = 0; i < sz; i++) {
            tab[i] = i;
        }
        numOfComp = 0;
    }

    void unify(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (h[a] > h[b]) {
            tab[b] = a;
            h[a] = max(h[a], h[b]+1);
        }
        else {
            tab[a] = b;
            h[b] = max(h[b], h[a]+1);
        }
        numOfComp--;
    }

    void addComp() {
        numOfComp++;
    }

    int getNumOfComp() {
        return numOfComp;
    }

private:
    vector<int> tab;
    vector<int> h;
    int numOfComp;

    int find(int x) {
        while (x != tab[x]) {
            x = tab[x];
        }
        return x;
    }
};

int main() {
    setIO("closing");
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    UnionFind uf(n);
    vector<bool> closed(n, true);
    vector<int> qv(n);
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        q--;
        qv[i] = q; 
    }

    std::reverse(qv.begin(), qv.end());

    vector<string> ans;
    for (auto q : qv) {
        uf.addComp();
        closed[q] = false;
        for (int child : a[q]) {
            if (!closed[child]) {
                uf.unify(q, child);
            }
        }

        if (uf.getNumOfComp() == 1)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }

    std::reverse(ans.begin(), ans.end());

    for (auto s : ans) {
        cout << s << endl;
    }

}