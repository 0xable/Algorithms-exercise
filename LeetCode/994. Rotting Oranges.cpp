// https://leetcode.com/problems/rotting-oranges/
// 12 ms
// 12.9 MB

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }
        
        if (freshCount == 0) return 0;
        int result = 0;
        int row, col;
        while (!q.empty()) {
            ++result;
            
            int curr = q.size();
            while (curr--) {
                auto p = q.front();
                q.pop();
                row = p.first;
                col = p.second;
                
                if (row > 0 && grid[row - 1][col] == 1) {
                    q.push(make_pair(row - 1, col));
                    grid[row - 1][col] = 2;
                    --freshCount;
                }
                if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
                    q.push(make_pair(row + 1, col));
                    grid[row + 1][col] = 2;
                    --freshCount;
                }
                if (col > 0 && grid[row][col - 1] == 1) {
                    q.push(make_pair(row, col - 1));
                    grid[row][col - 1] = 2;
                    --freshCount;
                }
                if (col + 1 < grid[row].size() && grid[row][col + 1] == 1) {
                    q.push(make_pair(row, col + 1));
                    grid[row][col + 1] = 2;
                    --freshCount;
                }
            }
        }
        
        return freshCount == 0 ? result - 1 : -1;
    }
};