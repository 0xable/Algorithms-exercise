// https://cses.fi/problemset/task/1745

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
 
    int maxValue = std::accumulate(coins.begin(), coins.end(), 0);
    vector<vector<bool>> values(n, vector<bool>(maxValue + 1, false));
    values[0][coins[0]] = true;
    for (int i = 1; i < n; ++i) {
        int current = coins[i];
        for (int j = 1; j <= maxValue; ++j) {
            values[i][j] = values[i - 1][j];
            if (j == current) {
                values[i][j] = true;
            }
            if (j - current > 0 && values[i - 1][j - current]) {
                values[i][j] = true;
            }
        }
    }
    int index = n - 1;
    int count = 0;
    vector<int> result;
    for (int i = 1; i <= maxValue; ++i) {
        if (values[index][i]) {
            result.push_back(i);
            ++count;
        }
    }
    cout << count << endl;
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}