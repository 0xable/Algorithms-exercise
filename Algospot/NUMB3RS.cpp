// https://algospot.com/judge/problem/read/NUMB3RS

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
    int n;
    int day;
    int start;
    vector<vector<int>> graph;
    vector<vector<double>> prob;
    vector<double> from;
    vector<int> target;
    
public:
    Solution(int n, int day, int start, vector<vector<int>>& graph, vector<int>& target)
    : n{n}, day{day}, start{start}, graph{graph}, target{target}, prob(day + 1, vector<double>(n, 0.0)), from(n) {
        for (int i = 0; i < n; ++i) {
            int size = graph[i].size();
            from[i] = 1.0 / size;
        }
        prob[0][start] = 1.0;
    }

    void search() {
        for (int d = 1; d <= day; ++d) {
            for (int town = 0; town < n; ++town) {
                if (prob[d - 1][town] == 0.0) continue;
                double curr = prob[d - 1][town];
                for (auto to : graph[town]) {
                    prob[d][to] += curr * from[town];
                }
            }
        }
    }

    void printAnswer() {
        cout << std::fixed << std::setprecision(12);
        for (auto k : target) {
            cout << prob[day][k] << " ";
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, d, start;
        cin >> n >> d >> start;
        vector<vector<int>> graph(n, vector<int>());
        int flag;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> flag;
                if (flag) graph[i].push_back(j);
            }
        }
        int q;
        cin >> q;
        vector<int> target(q);
        for (int i = 0; i < q; ++i) {
            cin >> target[i];
        }

        Solution s(n, d, start, graph, target);
        s.search();
        s.printAnswer();
    }
    return 0;
}