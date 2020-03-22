// https://cses.fi/problemset/task/1668

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
class Solution {
private:
    int n;
    vector<vector<int>> friendship;
    vector<int> group;
    vector<bool> visit;
 
public:
    Solution(int n, vector<vector<int>>&& friendship)
        : n(n), friendship(friendship) {
        group.assign(n + 1, -1);
        visit.assign(n + 1, false);
    }
 
    void solve() {
        if (search()) {
            for (int i = 1; i <= n; ++i) {
                if (group[i] == -1) {
                    cout << 1 << " ";
                } else {
                    cout << group[i] + 1 << " ";
                }
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
 
    bool search() {
        int curr;
        for (int i = 1; i <= n; ++i) {
            if (visit[i] || friendship[i].empty()) continue;
            curr = i;
            group[curr] = 0;
            queue<int> q;
            q.push(curr);
            while (!q.empty()) {
                curr = q.front();
                q.pop();
                visit[curr] = true;
 
                auto friends = friendship[curr];
                for (auto k : friends) {
                    if (group[curr] == group[k]) return false;
                    if (group[k] != -1) continue;
                    group[k] = group[curr] ^ 1;
                    q.push(k);
                }
            }
        }
        return true;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> friendship(n + 1);
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
 
    Solution s(n, std::move(friendship));
    s.solve();
    return 0;
}