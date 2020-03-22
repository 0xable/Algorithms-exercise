// https://algospot.com/judge/problem/read/JUMPGAME

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> board(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        queue<tuple<int, int>> q;
        q.push(make_tuple(0, 0));
        int x, y;
        while (!q.empty()) {
            tie(y, x) = q.front();
            q.pop();
            if (visited[y][x]) continue;
            visited[y][x] = true;
            if (y == n - 1 && x == n - 1) break;
            
            int step = board[y][x];
            if (y + step < n) {
                q.push(make_tuple(y + step, x));
            }
            if (x + step < n) {
                q.push(make_tuple(y, x + step));
            }
        }
        if (visited[n - 1][n - 1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}