// https://algospot.com/judge/problem/read/ARCTIC
// 44 ms

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

class Solution {
    int n;
    double maxDist;
    vector<vector<double>> dist;
    
public:
    Solution(int n, vector<pair<double, double>>& coordinate) : n{n}, dist(n, vector<double>(n, 0.0)) {
        double diffX, diffY, distance;
        maxDist = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                diffX = abs(coordinate[i].first - coordinate[j].first);
                diffY = abs(coordinate[i].second - coordinate[j].second);
                distance = sqrt(diffX * diffX + diffY * diffY);
                dist[i][j] = dist[j][i] = distance;
                if (maxDist < distance) maxDist = distance;
            }
        }
    }

    double search() {
        double distance = maxDist;
        double step = distance / 2;

        while (step > 0.0000000001) {
            while (distance - step > 0 && isPossible(distance - step)) {
                distance -= step;
            }
            step /= 2;
        }
        return distance;
    }

    bool isPossible(double distance) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && dist[curr][i] <= distance) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }
        return true;
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
        vector<pair<double, double>> coordinate(n);
        double x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            coordinate[i] = make_pair(x, y);
        }

        Solution s(n, coordinate);
        cout << setprecision(2) << std::fixed;
        cout << s.search() << endl;
    }
    return 0;
}