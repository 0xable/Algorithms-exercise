// https://algospot.com/judge/problem/read/TIMETRIP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
constexpr int INF = 987654321;
constexpr int INF2 = 87654321;

string getMinCost(vector<vector<pair<int, int>>>& graph, int v) {
    vector<int> upper(v, INF);
    upper[0] = 0;
    bool updated;
    int des, cost, prev;
    for (int i = 0; i < 2 * v; ++i) {
        updated = false;
        for (int src = 0; src < v; ++src) {
            for (auto p : graph[src]) {
                des = p.first;
                cost = p.second;
                if (upper[src] + cost < upper[des] && upper[src] + cost < INF2) {
                    updated = true;
                    upper[des] = upper[src] + cost;
                }
            }
        }
        if (!updated) break;
        if (i == v - 1) prev = upper[1];
    }
    if (updated && prev > upper[1]) return "INFINITY";
    if (upper[1] == INF) return "UNREACHABLE";
    return std::to_string(upper[1]);
}

string getMaxCost(vector<vector<pair<int, int>>>& graph, int v) {
    vector<int> lower(v, -INF);
    lower[0] = 0;
    bool updated;
    int des, cost, prev;
    for (int i = 0; i < v * 2; ++i) {
        updated = false;
        for (int src = 0; src < v; ++src) {
            for (auto p : graph[src]) {
                des = p.first;
                cost = p.second;
                if (lower[des] < lower[src] + cost && -INF2 < lower[src] + cost) {
                    updated = true;
                    lower[des] = lower[src] + cost;
                }
            }
        }
        if (!updated) break;
        if (i == v - 1) prev = lower[1];
    }
    if (updated && prev < lower[1]) return "INFINITY";
    return std::to_string(lower[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int v, w;
        cin >> v >> w;
        vector<vector<pair<int, int>>> graph(v, vector<pair<int, int>>());
        int src, des, cost;
        for (int i = 0; i < w; ++i) {
            cin >> src >> des >> cost;
            graph[src].push_back(make_pair(des, cost));
        }
        
        string result = getMinCost(graph, v);
        if (result == "UNREACHABLE") {
            cout << result << endl;
            continue;
        }
        cout << result << " " << getMaxCost(graph, v) << endl;
    }
    return 0;
}