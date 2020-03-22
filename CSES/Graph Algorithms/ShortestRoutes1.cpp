// https://cses.fi/problemset/task/1671

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long long n, m;
    const long long INF = 987654321987654321;
    cin >> n >> m;
    vector<vector<tuple<long long, long long>>> cost(n + 1, vector<tuple<long long, long long>>());
    vector<bool> visited(n + 1, false);
    vector<long long> result(n + 1, INF);
    for (long long i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        cost[a].push_back({b, c});
    }
 
    auto cmp = [](const tuple<long long, long long>& a, const tuple<long long, long long>& b) {
        return get<0>(a) > get<0>(b);
    };
    result[1] = 0;
    priority_queue<tuple<long long, long long>, vector<tuple<long long, long long>>, decltype(cmp)> pq(cmp);
    pq.push({0, 1});
    
    long long currentCost;
    long long currentIndex;
    while (!pq.empty()) {
        tie(currentCost, currentIndex) = pq.top();
        pq.pop();
        if (visited[currentIndex]) continue;
        visited[currentIndex] = true;
        
        for (auto stopover : cost[currentIndex]) {
            long long dest;
            long long addCost;
            tie(dest, addCost) = stopover;
            if (currentCost + addCost < result[dest]) {
                result[dest] = currentCost + addCost;
                pq.push(make_tuple(result[dest], dest));
            }
        }
    }
    
    ostream_iterator<long long> oi(cout, " ");
    std::copy(result.begin() + 1, result.end(), oi);
    return 0;
}