#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<bool>> graph;
    vector<int> result;
    vector<bool> visit;
public:
    Solution(vector<vector<bool>>& g) : graph{g}, visit(26, false) {

    }

    void dfs(int i) {
        visit[i] = true;
        for (int j = 0; j < 26; ++j) {
            if (graph[i][j] && !visit[j]) {
                dfs(j);
            }
        }
        result.push_back(i);
    }

    bool topologicalSort() {
        int n = 26;
        for (int i = 0; i < n; ++i)
            if (!visit[i]) dfs(i);

        std::reverse(result.begin(), result.end());
        
        // 만약 그래프가 DAG 가 아니라면 정렬 결과에 역방향 간선이 있다.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[result[j]][result[i]]) {
                    return false;
                }
            }
        }
        return true;
    }

    string getAnswer() {
        if (!topologicalSort()) return string("INVALID HYPOTHESIS");
        vector<char> res(result.size());
        std::transform(result.begin(), result.end(), res.begin(), [](int i) -> char {
            return 'a' + i;
        });
        return string(res.begin(), res.end());
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

        vector<vector<bool>> graph(26, vector<bool>(26, false));
        string prev;
        string curr;
        cin >> prev;
        for (int i = 1; i < n; ++i) {
            cin >> curr;
            int prevLen = prev.length();
            int currLen = curr.length();
            int minLen = std::min(prevLen, currLen);
            int j = 0;

            while (j < minLen) {
                if (prev[j] == curr[j]) {
                    ++j;
                    continue;
                }
                int k = prev[j] - 'a';
                int l = curr[j] - 'a';
                graph[k][l] = true;
                break;
            }
            prev = std::move(curr);
        }

        Solution s(graph);
        cout << s.getAnswer() << endl;
    }
    return 0;
}