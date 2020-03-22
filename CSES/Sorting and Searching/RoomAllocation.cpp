// https://cses.fi/problemset/task/1164

#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<tuple<int, int, int>> stay(n);
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        stay[i] = make_tuple(a, b, i);
    }
 
    std::sort(stay.begin(), stay.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<0>(a) < get<0>(b)) return true;
        if (get<0>(a) > get<0>(b)) return false;
        return get<1>(a) < get<1>(b);
    });
 
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    vector<int> allocation(n);
    q.push({get<1>(stay[0]), 1});
    allocation[get<2>(stay[0])] = 1;
 
    for (int i = 1; i < n; ++i) {
        bool checkin = false;
        auto early = q.top();
        
        if (early.first < get<0>(stay[i])) {
            q.pop();
            q.push({get<1>(stay[i]), early.second});
            allocation[get<2>(stay[i])] = early.second;
            checkin = true;
        }
        
        if (!checkin) {
            int roomNo = q.size() + 1;
            q.push({get<1>(stay[i]), roomNo});
            allocation[get<2>(stay[i])] = roomNo;
        }
    }
 
    cout << q.size() << endl;
    ostream_iterator<int> oi(cout, " ");
    std::copy(allocation.begin(), allocation.end(), oi);
    return 0;
}
