// https://cses.fi/problemset/task/1666

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
class Solution {
private:
    vector<int> connected;
    vector<int> size;
    set<int> notConnected;
    int n, m;
 
public:
    Solution() {
        cin >> n >> m;
        connected.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            connected[i] = i;
            size[i] = 1;
        }
 
        int from, to;
        for (int i = 0; i < m; ++i) {
            cin >> from >> to;
            from = getRoot(from);
            to = getRoot(to);
            if (from != to) {
                if (size[from] > size[to]) {
                    std::swap(from, to);
                }
                size[to] += size[from];
                connected[from] = to;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int k = getRoot(i);
            if (notConnected.count(k) == 0) {
                notConnected.insert(k);
            }
        }
    }
 
    int getRoot(int k) {
        while (k != connected[k]) {
            k = connected[k];
        }
        return k;
    }
 
    void getAnswer() {
        vector<pair<int, int>> result;
        cout << notConnected.size() - 1 << endl;
        auto iter = notConnected.begin();
        int start = *iter;
        iter++;
        while (iter != notConnected.end()) {
            cout << start << " " << *iter << endl;
            iter++;
        }
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    Solution s;
    s.getAnswer();
    return 0;
}