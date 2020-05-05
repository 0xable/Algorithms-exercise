// https://algospot.com/judge/problem/read/DRUNKEN

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    constexpr int INF = 987654321;

    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> order;
    vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));
    vector<vector<int>> total(v + 1, vector<int>(v + 1, INF));
    vector<int> delay(v + 1);
    int src, des, cost;
    for (int i = 1; i <= v; ++i) {
        cin >> cost;
        order.push_back(make_pair(cost, i));
        delay[i] = cost;
        dist[i][i] = 0;
        total[i][i] = 0;
    }
    std::sort(order.begin(), order.end());
    for (int i = 0; i < e; ++i) {
        cin >> src >> des >> cost;
        dist[src][des] = cost;
        dist[des][src] = cost;
        total[src][des] = cost;
        total[des][src] = cost;
    }
    
    for (int k = 0; k < v; ++k) {
        int via = order[k].second;
        for (int i = 1; i <= v; ++i) {
            for (int j = 1; j <= v; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][via] + dist[via][j]);
                total[i][j] = std::min(total[i][j], dist[i][via] + dist[via][j] + delay[via]);
            }
        }
    }

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> src >> des;
        cout << total[src][des] << endl;
    }
    return 0;
}