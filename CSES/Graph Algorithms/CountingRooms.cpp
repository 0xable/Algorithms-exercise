// https://cses.fi/problemset/task/1192

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
 
using namespace std;
 
class Solution {
private:
    int n, m;
    int count;
    vector<vector<char>> path;
 
public:
    Solution(int n, int m, vector<vector<char>>&& path) : n(n), m(m), path(path) {
        count = 0;
    }
 
    int solve() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (path[i][j] != '#') {
                    ++count;
                    search(i, j);
                }
            }
        }
        return count;
    }
 
    void search(int row, int col) {
        path[row][col] = '#';
        queue<pair<int, int>> coordinate;
        coordinate.push({row, col});
        int x, y;
        while (!coordinate.empty()) {
            auto k = coordinate.front();
            coordinate.pop();
            x = k.first;
            y = k.second;
            
            if (x - 1 >= 0 && path[x - 1][y] != '#') {
                path[x - 1][y] = '#';
                coordinate.push({x - 1, y});
            }
            if (y - 1 >= 0 && path[x][y - 1] != '#') {
                path[x][y - 1] = '#';
                coordinate.push({x, y - 1});
            }
            if (x + 1 < n && path[x + 1][y] != '#') {
                path[x + 1][y] = '#';
                coordinate.push({x + 1, y});
            }
            if (y + 1 < m && path[x][y + 1] != '#') {
                path[x][y + 1] = '#';
                coordinate.push({x, y + 1});
            }
        }
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<char>> path(n, vector<char>(m));
    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        for (int j = 0; j < m; ++j) {
            path[i][j] = temp[j];
        }
    }
 
    Solution s(n, m, std::move(path));
    cout << s.solve() << endl;
    return 0;