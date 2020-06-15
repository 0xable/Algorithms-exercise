// https://algospot.com/judge/problem/read/ARCTIC
// MST, 24 ms

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <iomanip>

using namespace std;

class Solution {
    int n;
    vector<vector<double>> dist;
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;

    vector<int> unions;
    vector<int> unionSize;
public:
    Solution(int n, vector<pair<double, double>>& coordinate) : n{n}, dist(n, vector<double>(n, 1e9)), unions(n), unionSize(n, 1) {
        double diffX, diffY, distance;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                diffX = abs(coordinate[i].first - coordinate[j].first);
                diffY = abs(coordinate[i].second - coordinate[j].second);
                distance = sqrt(diffX * diffX + diffY * diffY);
                dist[i][j] = dist[j][i] = distance;
                pq.push(make_tuple(distance, i, j));
            }
        }
        for (int i = 0; i < n; ++i) {
            unions[i] = i;
        }
    }

    int getRoot(int i) {
        if (unions[i] == i) return i;
        return unions[i] = getRoot(unions[i]);
    }

    void merge(int i, int j) {
        i = getRoot(i);
        j = getRoot(j);

        if (unionSize[i] < unionSize[j]) {
            std::swap(i, j);
        }
        unions[j] = i;
        if (unionSize[i] == unionSize[j]) unionSize[i]++;
    }

    double search() {
        double result;
        int node1, node2;
        tuple<double, int, int> next;
        while (!pq.empty()) {
            next = pq.top();
            pq.pop();
            tie(std::ignore, node1, node2) = next;
            node1 = getRoot(node1);
            node2 = getRoot(node2);
            if (node1 == node2) continue;
            merge(node1, node2);
            result = get<0>(next);
        }
        return result;
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