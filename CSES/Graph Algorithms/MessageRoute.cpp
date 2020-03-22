// https://cses.fi/problemset/task/1667

#include <iostream>
#include <vector>
#include <queue>
#include <string>
 
#define INF 987654321
 
using namespace std;
 
 
class Solution {
private:
    int n;
    vector<vector<int>> path;
    vector<int> totalCost;
public:
    Solution(int n, vector<vector<int>>&& path) : n(n), path(path) {
        totalCost.assign(n + 1, INF);
        totalCost[1] = 1;
    }
 
    void solve() {
        if (search()) {
            vector<int> result = backtrackRoute();
            cout << result.size() << endl;
            for (auto k : result) {
                cout << k << " ";
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
 
    bool search() {
        int cost = 2;
        queue<int> q;
        queue<int> standby;
        q.push(1);
        while (true) {
            if (q.empty()) {
                if (standby.empty()) {
                    return false;
                }
                q = std::move(standby);
                ++cost;
            }
 
            int curr = q.front();
            q.pop();
            
            auto nextlist = path[curr];
            for (auto k : nextlist) {
                if (totalCost[k] != INF) continue;
                totalCost[k] = cost;
                if (k == n) return true;
                standby.push(k);
            }
        }
    }
 
    vector<int> backtrackRoute() {
        vector<int> result = {n};
        int cost = totalCost[n] - 1;
        int curr = n;
        while (curr != 1) {
            auto nextlist = path[curr];
            for (auto k : nextlist) {
                if (totalCost[k] == cost) {
                    result.push_back(k);
                    curr = k;
                    --cost;
                    break;
                }
            }
        }
        vector<int> temp(result.rbegin(), result.rend());
        return temp;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n + 1);
    
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
 
    Solution s(n, std::move(path));
    s.solve();
    return 0;
}