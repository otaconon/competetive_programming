#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
template <typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> cnt(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[--x]++;
    }
    
    // Read the queries and sort them, so that they can be answered online in a convenient order
    vector<pair<ll, int>> queries(q);
    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        queries[i] = {k - n, i};
    }
    sort(queries.begin(), queries.end());

    // Sort the cities by the number of occurences, keeping track of the original index
    vector<pair<ll, int>> occ(m);
    for (int i = 0; i < m; i++)
        occ[i] = {cnt[i], i};
    sort(occ.begin(), occ.end());

    Tree<int> cities; // track cities that evened out the occurances with previous cities
    vector<int> ans(q, -1); // answers offline
    ll year = 1; // current year of the query

    // iterate over all cities in sorrted order
    for (int i = 0; i < m-1; i++) {
        cities.insert(occ[i].second);

        ll r = year + (occ[i+1].first - occ[i].first) * (i+1); // calculate the year at which the current city, and all the prvious ones have the same number of occurences as the next city
        ll l = lower_bound(queries.begin(), queries.end(), make_pair(year, 0)) - queries.begin(); // find the index of first query that request year later than r
        // iterate over queries that fit in our range. For each query find the (query_year - year) % (i+1)-th city.
        for (int j = l; j < q && queries[j].first < r; j++) {
            auto& [query_year, query_idx] = queries[j];
            ans[query_idx] = *cities.find_by_order((query_year - year) % (i+1));
        }
        year = r;
    }

    // Prepare answer for the queries that happen after all cities are circulating
    for (int i = 0; i < q; i++) {
        if (ans[queries[i].second] == -1) {
            ans[queries[i].second] = (queries[i].first - year) % m;
        }
    }

    for (auto& x : ans)
        cout << x + 1 << endl;
}