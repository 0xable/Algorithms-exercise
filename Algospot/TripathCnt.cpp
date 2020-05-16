// https://algospot.com/judge/problem/read/TRIPATHCNT

#include <iostream>
#include <vector>

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
        vector<vector<int>> sum(n, vector<int>(n, 0));
        vector<vector<int>> path(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> triangle[i][j];
            }
        }
        sum[0][0] = triangle[0][0];
        path[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    sum[i][j] = sum[i - 1][0] + triangle[i][j];
                    path[i][j] = path[i - 1][0];
                } else if (j == i) {
                    sum[i][j] = sum[i - 1][j - 1] + triangle[i][j];
                    path[i][j] = path[i - 1][j - 1];
                } else {
                    if (sum[i - 1][j - 1] == sum[i - 1][j]) {
                        path[i][j] = path[i - 1][j - 1] + path[i - 1][j];
                    } else if (sum[i - 1][j - 1] > sum[i - 1][j]) {
                        path[i][j] = path[i - 1][j - 1];
                    } else {
                        path[i][j] = path[i - 1][j];
                    }
                    sum[i][j] = std::max(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j];
                }
            }
        }
        int count = 0;
        int max = -1;
        for (int i = 0; i < n; ++i) {
            if (max < sum[n - 1][i]) max = sum[n - 1][i];
        }
        for (int i = 0; i < n; ++i) {
            if (max == sum[n - 1][i]) count += path[n - 1][i];
        }
        cout << count << endl;
    }
    return 0;
}