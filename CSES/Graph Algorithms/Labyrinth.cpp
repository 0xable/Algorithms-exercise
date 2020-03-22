// https://cses.fi/problemset/task/1193

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
 
using namespace std;
 
class Solution {
private:
    int n, m;
    int length;
    int startX, startY;
    int endX, endY;
    vector<vector<char>> maze;
    vector<vector<int>> router;
    string path;
    bool solve;
 
public:
    Solution(int n, int m, vector<vector<char>>&& maze) : n(n), m(m), maze(maze) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == 'A') {
                    startX = i;
                    startY = j;
                }
                if (maze[i][j] == 'B') {
                    endX = i;
                    endY = j;
                }
            }
        }
        length = 0;
        solve = false;
        router.assign(n, vector<int>(m, -1));
    }
 
    void search(int x, int y) {
        maze[x][y] = '#';
        auto k = make_tuple(x, y, 0);
        queue<tuple<int, int, int>> q;
        q.push(k);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
 
            int row, col, length;
            std::tie(row, col, length) = curr;
            router[row][col] = length;
            if (row == endX && col == endY) {
                this -> length = length;
                this -> solve = true;
                backtrackingPath();
                break;
            }
 
            if (col - 1 >= 0 && maze[row][col - 1] != '#') {
                q.push(make_tuple(row, col - 1, length + 1));
                maze[row][col - 1] = '#';
            }
            if (row - 1 >= 0 && maze[row - 1][col] != '#') {
                q.push(make_tuple(row - 1, col, length + 1));
                maze[row - 1][col] = '#';
            }
            if (col + 1 < m && maze[row][col + 1] != '#') {
                q.push(make_tuple(row, col + 1, length + 1));
                maze[row][col + 1] = '#';
            }
            if (row + 1 < n && maze[row + 1][col] != '#') {
                q.push(make_tuple(row + 1, col, length + 1));
                maze[row + 1][col] = '#';
            }
        }
    }
 
    void search() {
        search(startX, startY);
    }
 
    void backtrackingPath() {
        int row = endX;
        int col = endY;
        int cnt = length - 1;
        string route;
        while (row != startX || col != startY) {
            if (row - 1 >= 0 && router[row - 1][col] == cnt) {
                route.push_back('D');
                cnt--;
                --row;
                continue;
            }
            if (row + 1 < n && router[row + 1][col] == cnt) {
                route.push_back('U');
                cnt--;
                ++row;
                continue;
            }
            if (col - 1 >= 0 && router[row][col - 1] == cnt) {
                route.push_back('R');
                cnt--;
                --col;
                continue;
            }
            if (col + 1 < m && router[row][col + 1] == cnt) {
                route.push_back('L');
                cnt--;
                ++col;
                continue;
            }
        }
        path.resize(route.size());
        std::copy(route.rbegin(), route.rend(), path.begin());
    }
 
    void getAnswer() {
        if (solve) {
            cout << "YES" << endl;
            cout << length << endl;
            cout << path << endl;
        } else {
            cout << "NO" << endl;
        }
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; ++j) {
            maze[i][j] = temp[j];
        }
    }
 
    Solution s(n, m, std::move(maze));
    s.search();
    s.getAnswer();
    return 0;
}