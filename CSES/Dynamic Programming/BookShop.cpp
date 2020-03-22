// https://cses.fi/problemset/task/1158

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, budget;
    cin >> n >> budget;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    vector<int> pages(n);
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
 
    vector<vector<int>> table(n, vector<int>(budget + 1, 0));
    for (int i = 0; i <= budget; ++i) {
        table[0][i] = prices[0] > i ? 0 : pages[0];
    }
 
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= budget; ++j) {
            if (j < prices[i]) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = std::max(table[i - 1][j - prices[i]] + pages[i], table[i - 1][j]);
            }
        }
    }
    cout << table[n - 1][budget] << endl;
    return 0;
}