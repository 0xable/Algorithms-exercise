// https://algospot.com/judge/problem/read/CANADATRIP
// 48 ms

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
    int n, k;
    vector<tuple<int, int, int>> table;

public:
    Solution(int n, int k, vector<tuple<int, int, int>> table) : n{n}, k{k}, table{table} {

    }

    int search() {
        int dist = 8030000;
        int step = dist / 2;
        while (step) {
            while (dist - step > 0 && isPossible(dist - step)) {
                dist -= step;
            }
            step /= 2;
        }
        return dist;
    }

    bool isPossible(int dist) {
        int count = 0;
        int distance, before, interval; 
        for (int i = 0; i < n; ++i) {
            tie(distance, before, interval) = table[i];
            if (distance - before > dist) continue;
            ++count;
            count += (std::min(distance, dist) - (distance - before)) / interval;
        }
        if (count >= k) return true;
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<tuple<int, int, int>> table(n);
        int dist, before, interval;
        for (int i = 0; i < n; ++i) {
            cin >> dist >> before >> interval;
            table[i] = make_tuple(dist, before, interval);
        }

        Solution s(n, k, table);
        cout << s.search() << endl;
    }
    return 0;
}