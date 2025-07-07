/*
    A failed attempt at reading a question. Tried to solve a harder version of: https://codeforces.com/problemset/problem/1881/F

    In my head i was supposed to find a node that has a minimum sum of distances to all marked nodes
*/


#include <bits/stdc++.h>

using namespace std;

void print_tree(vector<vector<int>>& tree) {
    for (size_t i = 0; i < tree.size(); i++) {
        cout << i << ": ";
        for (auto& x : tree[i]) {
            cout << x << " ";
        }
        cout << endl;
    } 
}

void print_gsum(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        cout << i << ": " << vec[i] << endl; 
    }
}

int n, k;
int whole_dist = 0;
vector<bool> vs;
vector<bool> marked;
vector<vector<int>> g;
void find_whole_dist(int node, int dist) {
    if (vs[node]) {
        return;
    }

    if (marked[node])
        whole_dist += dist;

    for (auto& child : g[node]) {
        find_whole_dist(child, dist++);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vs.resize(n-1);
        marked.resize(n-1);
        g.resize(n-1);

        vector<int> gsum(n); 
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x--;
            marked[x] = true;
            gsum[x]++;
        }
 
        for (int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        queue<int> leafes;
        vector<bool> visited(n);
        set<int> to_push;
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) {
                to_push.insert(i);
                visited[i] = true;
            }
        }
        
        while (!to_push.empty()) {
            for (auto& x : to_push) {
                leafes.push(x);
                visited[x] = true;
            }
            to_push.clear();
            
            while (!leafes.empty()) {
                int current_node = leafes.front();
                leafes.pop();

                for (auto& child : g[current_node]) {
                    if (!visited[child]) {
                        to_push.insert(child);
                        gsum[child] += gsum[current_node];
                    }
                }
            }
        }

        pair<int, int> best = {0, 0};
        for (int i = 0; i < n-1; i++) {
            if (gsum[i] > best.second) {
                best = {i, gsum[i]};
            }
        } 

        find_whole_dist(best.first, 0);

        int node = best.first;
        while (true) {
            // to be complete at some point in time;
        }

        print_tree(g);
        print_gsum(gsum);
        
    }
}