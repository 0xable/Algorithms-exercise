// https://cses.fi/problemset/task/1746

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1000000007;
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<vector<int>> table(n, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (arr[0] == 0) {
        std::fill(table[0].begin(), table[0].end(), 1);
    } else {
        table[0][arr[0]] = 1;
    }

    int curr;
    for (int i = 1; i < n; ++i) {
        curr = arr[i];
        if (curr == 0) {
            for (int j = 1; j <= m; ++j) {
                if (j == 1) {
                    table[i][j] = (table[i - 1][j] + table[i - 1][j + 1]) % MOD;
                } else if (j == m) {
                    table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
                } else {
                    table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
                    table[i][j] = (table[i][j] + table[i - 1][j + 1]) % MOD;
                }
            }
        } else {
            if (curr == 1) {
                table[i][curr] = (table[i - 1][curr] + table[i - 1][curr + 1]) % MOD;
            } else if (curr == m) {
                table[i][curr] = (table[i - 1][curr - 1] + table[i - 1][curr]) % MOD;
            } else {
                table[i][curr] = (table[i - 1][curr - 1] + table[i - 1][curr]) % MOD;
                table[i][curr] = (table[i][curr] + table[i - 1][curr + 1]) % MOD;
            }
        }
    }
    
    long long result = std::accumulate(table[n - 1].begin(), table[n - 1].end(), 0LL);
    result %= MOD;
    cout << result << endl;
    return 0;
}