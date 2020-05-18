// https://algospot.com/judge/problem/read/POLY

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int n;
    int result;
    vector<vector<int>> table;

public:
    Solution(int n) : table(n + 1, vector<int>(n + 1, -1)) {

    }

    int search(int n) {
        int result = 0;
        for (int upper = 1; upper <= n; ++upper) {
            result = (result + search(n - upper, upper)) % 10000000;
        }
        return result;
    }

    int search(int n, int upper) {
        if (n == 0) return 1;
        if (table[n][upper] != -1) return table[n][upper];
        int result = 0;
        for (int step = 1; step <= n; ++step) {
            result = (result + (upper + step - 1) * search(n - step, step)) % 10000000;
        }
        return table[n][upper] = result;
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
        Solution s(n);
        cout << s.search(n) << endl;
    }
    return 0;
}