// https://algospot.com/judge/problem/read/PROMISES

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    constexpr int INF = 987654321;

    int tc;
    cin >> tc;
    while (tc--) {
        int v, m, n;
        cin >> v >> m >> n;
        vector<vector<int>> graph(v, vector<int>(v, INF));
        vector<tuple<int, int, int>> plan(n);
        for (int i = 0; i < v; ++i) graph[i][i] = 0;
        int src, des, cost;
        for (int i = 0; i < m; ++i) {
            cin >> src >> des >> cost;
            graph[src][des] = std::min(graph[src][des], cost);
            graph[des][src] = std::min(graph[des][src], cost);
        }

        for (int i = 0; i < n; ++i) {
            cin >> src >> des >> cost;
            plan[i] = make_tuple(src, des, cost);
        }

        for (int k = 0; k < v; ++k) {
            for (int i = 0; i < v; ++i) {
                for (int j = 0; j < v; ++j) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        int result = 0;
        for (int k = 0; k < n; ++k) {
            tie(src, des, cost) = plan[k];
            if (graph[src][des] <= cost) {
                ++result;
                continue;
            }
            for (int i = 0; i < v; ++i) {
                for (int j = 0; j < v; ++j) {
                    graph[i][j] = std::min(graph[i][j], std::min(graph[i][src] + cost + graph[des][j], graph[i][des] + cost + graph[src][j]));
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}