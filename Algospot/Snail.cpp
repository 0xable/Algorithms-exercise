// https://algospot.com/judge/problem/read/SNAIL

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    vector<vector<double>> table(1001, vector<double>(1001));
    table[1][0] = 0.25;
    table[1][1] = 0.75;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                table[i][j] = table[i - 1][j] * 0.25;
            } else if (j == i) {
                table[i][j] = table[i - 1][j - 1] * 0.75;
            } else {
                table[i][j] = table[i - 1][j - 1] * 0.75 + table[i - 1][j] * 0.25;
            }
        }
    }
    
    while (tc--) {
        int n, m;
        cin >> n >> m;
        cout << std::fixed << std::setprecision(12);
        if (n == m) {
            cout << 1.0 << endl;
            continue;
        } else if (n > 2 * m) {
            cout << 0.0 << endl;
            continue;
        }
        double result = 0.0;
        int diff = n - m - 1;
        while (diff >= 0) {
            result += table[m][diff];
            --diff;
        }
        cout << 1.0 - result << endl;
    }
    return 0;
}