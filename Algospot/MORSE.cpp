// https://algospot.com/judge/problem/read/MORSE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int>> bc;
public:
    Solution() : bc(201, vector<int>(201, 0)) {
        for (int i = 1; i <= 200; ++i) {
            bc[i][0] = bc[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                bc[i][j] = std::min(1010000000, bc[i - 1][j - 1] + bc[i - 1][j]);
            }
        }
    }

    string getCode(int n, int m, int k) {
        string result;
        search(n, m, k, result);
        return result;
    }

    void search(int n, int m, int k, string& result) {
        if (n == 0 && m == 0) return;
        if (bc[n + m - 1][m] == k) {
            result += '-';
            result += string(m, 'o');
            result += string(n - 1, '-');
        } else if (bc[n + m - 1][m] < k) {
            result += 'o';
            search(n, m - 1, k - bc[n + m - 1][m], result);
        } else {
            result += '-';
            search(n - 1, m, k, result);
        }
        return;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << s.getCode(n, m, k) << endl;
    }
    return 0;
}