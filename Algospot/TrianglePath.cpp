// https://algospot.com/judge/problem/read/TRIANGLEPATH

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> triangle[i][j];
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][0];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += std::max(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        cout << *std::max_element(triangle[n - 1].begin(), triangle[n - 1].end()) << endl;
    }
    return 0;
}