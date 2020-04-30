// https://algospot.com/judge/problem/read/WORDCHAIN

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<string> table[26][26];
    vector<int> indegree;
    vector<int> outdegree;
    vector<int> circuit;
    int n;

    int charToInt(char ch) {
        return ch - 'a';
    }

public:
    Solution(int n, vector<string>& words) : n{n}, graph(26, vector<int>(26, 0)), indegree(26, 0), outdegree(26, 0), circuit() {
        for (int i = 0; i < n; ++i) {
            int begin = charToInt(words[i][0]);
            int end = charToInt(words[i].back());
            graph[begin][end]++;
            indegree[end]++;
            outdegree[begin]++;
            table[begin][end].push_back(words[i]);
        }
    }

    bool check() {
        int in = 0;
        int out = 0;
        for (int i = 0; i < 26; ++i) {
            int diff = indegree[i] - outdegree[i];
            if (diff > 1 || diff < -1) return false;
            if (diff == 1) ++in;
            if (diff == -1) ++out;
        }
        return (in == 1 && out == 1) || (in == 0 && out == 0);
    } 

    void search() {
        if (!check()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        for (int i = 0; i < 26; ++i) {
            if (outdegree[i] == indegree[i] + 1) {
                getEulerCircuitOrTrail(i);
                printAnswer();
                return;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (outdegree[i] > 0) {
                getEulerCircuitOrTrail(i);
                printAnswer();
                return;
            }
        }
    }

    void getEulerCircuitOrTrail(int i) {
        for (int j = 0; j < 26; ++j) {
            while (graph[i][j] > 0) {
                graph[i][j]--;
                getEulerCircuitOrTrail(j);
            }
        }
        circuit.push_back(i);
    }

    void printAnswer() {
        if (circuit.size() != n + 1) {
            cout << "IMPOSSIBLE" << endl;
        }

        vector<string> result(n);
        std::reverse(circuit.begin(), circuit.end());
        int prev = circuit[0];
        int curr;
        int j = 0;
        for (int i = 1; i <= n; ++i, ++j) {
            curr = circuit[i];
            result[j] = table[prev][curr].back();
            table[prev][curr].pop_back();
            prev = curr;
        }
        ostream_iterator<string> oi(cout, " ");
        std::copy(result.begin(), result.end(), oi);
        cout << endl;
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
        vector<string> words(n);
        string temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            words[i] = temp;
        }
        
        Solution s(n, words);
        s.search();
    }
    return 0;
}