// https://cses.fi/problemset/task/1638

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<vector<int>> path(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; ++j) {
            path[i][j] = temp[j] == '.' ? 0 : -1;
        }
    }
 
    if (path[0][0] == -1 || path[n - 1][n - 1] == -1) {
        cout << 0 << endl;
        return 0;
    }
    path[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (path[i][0] == -1) continue;
        path[i][0] = path[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
        if (path[0][i] == - 1) continue;
        path[0][i] = path[0][i - 1];
    }
 
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (path[i][j] == -1) {
                continue;
            } else if (path[i - 1][j] == -1 && path[i][j - 1] == -1) {
                path[i][j] = -1;
            } else if (path[i -1][j] == -1) {
                path[i][j] = path[i][j - 1];
            } else if (path[i][j - 1] == -1) {
                path[i][j] = path[i - 1][j];
            } else {
                path[i][j] = (path[i - 1][j] + path[i][j - 1]) % 1000000007;
            }
        }
    }
 
    cout << (path[n - 1][n - 1] == -1 ? 0 : path[n - 1][n - 1]) << endl;
    return 0;
}