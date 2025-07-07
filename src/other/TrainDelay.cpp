#include <bits/stdc++.h>

using namespace std;

enum class eventType {
    ARRIVAL, DEPARTURE
};

struct event {
    eventType type;
    int time;
    int city;
    int train;

    event(eventType type, int time, int city, int train) 
    : type(type),
    time(time),
    city(city),
    train(train)
    {}

    bool operator<(const event& other) {
        if (time != other.time) {
            return time < other.time;
        }
        return type == eventType::ARRIVAL && other.type == eventType::DEPARTURE;
    }
};

int main() {
    int n, m, x1;
    cin >> n >> m >> x1;
    vector<event> events;

    for (int i = 0; i < m; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        a--; b--;
        events.emplace_back(eventType::ARRIVAL, t, b, i);
        events.emplace_back(eventType::DEPARTURE, s, a, i);
    }

    sort(events.begin(), events.end());

    vector<int> cities(n);

    vector<int> ans(m);
    ans[0] = x1;
    
    for (int i = 0; i < m*2; i++) {
        event e = events[i];
        if (e.type == eventType::ARRIVAL) {
            cities[e.city] = max(cities[e.city], e.time + ans[e.train]);
        }
        else {
            if (e.train)
                ans[e.train] = max(0, cities[e.city] - e.time);
        }
    }

   for (int i = 1; i < m; i++) {
        cout << ans[i] << ' ';
   }
}