// https://algospot.com/judge/problem/read/GENIUS
// 19604 ms ...

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k, m;
        cin >> n >> k >> m;
        
        vector<vector<double>> table(8, vector<double>(n, 0.0));
        vector<int> time(n, 0);
        vector<vector<double>> conditionalProb(n, vector<double>(n, 0.0));
        vector<int> like(m, 0);

        for (int i = 0; i < n; ++i) {
            cin >> time[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> conditionalProb[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            cin >> like[i];
        }
        
        table[0][0] = 1;
        int runtime;
        int t = 0;
        while (t <= k) {
            int erase = (t + 4) % 8;
            for (int i = 0; i < n; ++i) {
                table[erase][i] = 0.0;
            }

            for (int i = 0; i < n; ++i) {
                if (table[t % 8][i] != 0.0) {
                    runtime = time[i];
                    for (int j = 0; j < n; ++j) {
                        table[(t + runtime) % 8][j] += table[t % 8][i] * conditionalProb[i][j];
                    }
                
                }
            }
            ++t;
        }
        
        vector<double> result(n, 0.0);
        for (int i = 0; i < n; ++i) {
            t = k - time[i] + 1;
            while (t <= k) {
                result[i] += table[t % 8][i];
                ++t;
            }
        }
        cout << std::fixed << std::setprecision(12);
        for (auto k : like) {
            cout << result[k] << " ";
        }
        cout << endl;
    }
    return 0;
}