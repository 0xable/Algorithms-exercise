// https://algospot.com/judge/problem/read/TSP1
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p317 - 319 참조
// 4 ms

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

class Solution {
    int n;
    vector<vector<double>> dist;
    vector<vector<double>> cache;
    int start;
    const double INF;
public:
    Solution(int n, vector<vector<double>>& d) : n{n}, dist{d}, INF{numeric_limits<double>::max()} {
        cache.assign(n, vector<double>((1 << n) - 1, -1.0));
    }

    double search() {
        double result = INF;
        for (int next = 0; next < n; ++next) {
            start = next;
            result = std::min(result, shortestPath(next, (1 << next)));
        }
        return result;
    }

    double shortestPath(int here, int visited) {
        // 모든 도시를 다 방문했을 때는 종료한다.
        if (visited == (1 << n) - 1) return 0.0;
        if (cache[here][visited] != -1.0) return cache[here][visited];
        
        double result = INF;
        for (int next = 0; next < n; ++next) {
            if (visited & (1 << next)) continue;
            double cand = dist[here][next] + shortestPath(next, visited + (1 << next));
            result = std::min(result, cand);
        }
        return cache[here][visited] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<double>> dist(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> dist[i][j];
            }
        }
        Solution s(n, dist);
        cout << std::fixed << std::setprecision(12);
        cout << s.search() << endl;
    }
    return 0;
}