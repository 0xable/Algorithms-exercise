// https://cses.fi/problemset/task/1093

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    constexpr long long MOD = 1e9 + 7;
    int n;
    cin >> n;
    
    if (n == 3) {
        cout << 1 << endl;
        return 0;
    }
    
    int product = n * (n + 1);
    if (product % 4 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int sum = product / 4;
    vector<vector<int>> table(n, vector<int>(sum + 1, 0));
    for (int num = 1; num < n; ++num) {
        table[num - 1][0] = 1;
        for (int k = 1; k <= sum; ++k) {
            if (k < num || table[num - 1][k - num] == 0) {
                table[num][k] = table[num - 1][k];
            } else {
                table[num][k] = (table[num - 1][k] + table[num - 1][k - num]) % MOD;
            }
        }
    }

    int result = table[n - 1][sum - n];
    cout << result << endl;
    return 0;
}